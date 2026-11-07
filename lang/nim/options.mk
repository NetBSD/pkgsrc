# $NetBSD: options.mk,v 1.1 2026/11/07 22:43:53 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nim
PKG_SUPPORTED_OPTIONS=	doc
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

# This will build the documentation for nim. Because both post-build and
# post-install are not defined prior to this, we can safely just initialize
# them here. Note that to build the documentation, NodeJS is needed, which
# is quite large.
.if !empty(PKG_OPTIONS:Mdoc)
.include "../../lang/nodejs/buildlink3.mk"

USE_LANGUAGES+=	c++
PLIST_SRC+=	PLIST
PLIST_SRC+=	PLIST.doc

post-build:
	# Build docs
	cd ${WRKSRC} && ./koch \
		docs \
		--parallelBuild:${_MAKE_JOBS_N}

INSTALLATION_DIRS+=	share/doc/nim

post-install:
	# Copy over docs to ${DESTDIR}
	cd ${WRKSRC} && ${CP} -r doc/html/* ${DESTDIR}${PREFIX}/share/doc/nim

.endif
