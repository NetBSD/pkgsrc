# $NetBSD: go-dep.mk,v 1.2 2019/09/10 20:01:06 rillig Exp $
#
# This file implements dep (https://github.com/golang/dep) support in pkgsrc.
#
# === Package-settable variables ===
#
# GO_DEPS
#	This is a list of dependencies of the format url:sha[:dir].  These
#	dependencies can be generated using the print-go-deps helper target
#	against an extracted WRKSRC, which parses the Godeps file contained in
#	the source that would normally be used by dep.
#
#	Currently only GitHub URLs are supported, so if a Godeps dependency
#	uses a different URL, the equivalent GitHub URL needs to be calculated
#	and the original URL added as the optional :dir argument.  This file
#	contains a list of GODEP_REDIRECTS which translates common redirects,
#	and additions to this list are encouraged.
#
#	The print-go-deps target will reduce SHA strings to the first 8
#	characters to avoid long lines, but the extracted archive will use the
#	full SHA.
#
#	Examples:
#		github.com/golang/protobuf:92554152
#		github.com/collectd/go-collectd:2ce14454:collectd.org
#		github.com/uber-go/atomic:8474b86a:go.uber.org/atomic
#		github.com/golang/time:26559e0f:golang.org/x/time
#
# GODEP_REDIRECTS
#	Maps a URL or subset of a URL to its GitHub equivalent.  URLs that are
#	likely to be used across multiple packages should be added to this
#	file, otherwise add them to the individual package Makefile.
#
#	Examples:
#		collectd.org=github.com/collectd/go-collectd
#		golang.org/x=github.com/golang
#
# Keywords: go golang deps go-deps print-go-deps

_VARGROUPS+=		godeps
_PKG_VARS.godeps=	GO_DEPS GODEP_REDIRECTS
_USE_VARS.godeps=	PKGNAME_NOREV \
			MASTER_SITE_GITHUB DEFAULT_DISTFILES \
			WRKDIR BUILDLINK_DIR DESTDIR PREFIX \
			TEST_ENV
_DEF_VARS.godeps=	DISTFILES DIST_SUBDIR MAKE_ENV \
			${GO_DEPS:@dep@ \
				${:U GODEP_URL GODEP_SHA GODEP_DIR GODEP_TGZ \
					:@var@${var}.${dep} @} \
				SITES.${GODEP_TGZ.${dep}} @} \
			PRINT_PLIST_AWK
_IGN_VARS.godeps=	_GODEP_AWK _GO_DIST_BASE
_LISTED_VARS.godeps=	GO_DEPS GODEP_REDIRECTS DISTFILES *_ENV

#
# When using GO_DEPS a lot of additional distfiles will be added with just SHAs
# for their filename.  Setting DIST_SUBDIR is required to keep things sensible.
#
DIST_SUBDIR=		${PKGNAME_NOREV}

#
# For now fetching via GitHub is mandatory.
#
DISTFILES?=			${DEFAULT_DISTFILES}
.for dep in ${GO_DEPS}
GODEP_URL.${dep}:=		${dep:C/:/ /g:[1]}
GODEP_SHA.${dep}:=		${dep:C/:/ /g:[2]}
GODEP_DIR.${dep}:=		${dep:C/:/ /g:[3]}
.  if empty(GODEP_DIR.${dep})
GODEP_DIR.${dep}:=		${GODEP_URL.${dep}}
.  endif
GODEP_TGZ.${dep}:=		${GODEP_SHA.${dep}}.tar.gz
SITES.${GODEP_TGZ.${dep}}:=	${MASTER_SITE_GITHUB}${GODEP_URL.${dep}:S,github.com/,,}/archive/
DISTFILES+=			${GODEP_TGZ.${dep}}

.PHONY: post-extract-${GODEP_URL.${dep}}
post-extract: post-extract-${GODEP_URL.${dep}}
post-extract-${GODEP_URL.${dep}}:
	# We can't use :H here as the GODEP_DIR might just be a host.name
	@${MKDIR} `${DIRNAME} ${WRKDIR}/src/${GODEP_DIR.${dep}}`
	# The * glob is used as we shorten the SHA to 8 characters to keep
	# GO_DEPS lines a reasonable length, but the extracted distfile uses
	# the full SHA.
	@${MV} ${WRKDIR}/${GODEP_URL.${dep}:T}-${GODEP_SHA.${dep}}* \
		${WRKDIR}/src/${GODEP_DIR.${dep}}
.endfor

#
# Non-GitHub sites which are listed in Godeps files but redirect to GitHub.  We
# fetch them from GitHub but move the source to the expected directory name.
#
GODEP_REDIRECTS+=	collectd.org=github.com/collectd/go-collectd
GODEP_REDIRECTS+=	go.uber.org=github.com/uber-go
GODEP_REDIRECTS+=	go4.org=github.com/go4org/go4
GODEP_REDIRECTS+=	golang.org/x=github.com/golang
GODEP_REDIRECTS+=	google.golang.org/appengine=github.com/golang/appengine
GODEP_REDIRECTS+=	google.golang.org/genproto=github.com/google/go-genproto
GODEP_REDIRECTS+=	google.golang.org/grpc=github.com/grpc/grpc-go
GODEP_REDIRECTS+=	gopkg.in/DATA-DOG/go-sqlmock.v1=github.com/DATA-DOG/go-sqlmock
GODEP_REDIRECTS+=	gopkg.in/check.v1=github.com/go-check/check
GODEP_REDIRECTS+=	gopkg.in/mgo.v2=github.com/go-mgo/mgo
GODEP_REDIRECTS+=	gopkg.in/tomb.v2=github.com/go-tomb/tomb
GODEP_REDIRECTS+=	gopkg.in/yaml.v2=github.com/go-yaml/yaml
GODEP_REDIRECTS+=	honnef.co/go/tools=github.com/dominikh/go-tools

.for url in ${GODEP_REDIRECTS}
_GODEP_FROM.${url}:=	${url:C/=/ /g:[1]}
_GODEP_TO.${url}:=	${url:C/=/ /g:[2]}
.endfor

#
# Add a print-go-deps target to aid GO_DEPS generation.  This depends on the
# current format of the Gopkg.lock file which may change.
#
_GODEP_AWK+=	BEGIN { name=""; rev=""; dir=""; }
_GODEP_AWK+=	$$1 == "name" {						\
			gsub(/\"/, "", $$NF);				\
			${GODEP_REDIRECTS:@url@				\
			if (match($$NF, "^${_GODEP_FROM.${url}}")) {	\
				dir=$$NF;				\
				gsub("^${_GODEP_FROM.${url}}",		\
				    "${_GODEP_TO.${url}}", $$NF);	\
			}@}						\
			name = $$NF;					\
		}
_GODEP_AWK+=	$$1 == "revision" {					\
			gsub(/\"/, "", $$NF);				\
			rev = substr($$NF, 1, 8);			\
		}
_GODEP_AWK+=	name && rev {						\
			printf("GO_DEPS+=\t%s:%s%s\n",			\
			    name, rev,					\
			    (dir) ? ":" dir : "");			\
			name=""; rev=""; dir="";			\
		}

.PHONY: print-go-deps
print-go-deps:
	${RUN} ${AWK} ${_GODEP_AWK:Q} ${WRKSRC}/Gopkg.lock
