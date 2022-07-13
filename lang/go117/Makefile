# $NetBSD: Makefile,v 1.7 2022/07/13 14:14:18 bsiegert Exp $

.include "../../lang/go/version.mk"
.include "../../lang/go/bootstrap.mk"

GOVERSSUFFIX=	117

DISTNAME=	go${GO${GOVERSSUFFIX}_VERSION}.src
PKGNAME=	go${GOVERSSUFFIX}-${GO${GOVERSSUFFIX}_VERSION}
CATEGORIES=	lang
MASTER_SITES=	https://storage.googleapis.com/golang/

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://golang.org/
COMMENT=	The Go programming language
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/go
USE_TOOLS+=	bash:run perl:run pax

# cgo compiles under TMPDIR
TMPDIR?=	/tmp
BUILDLINK_PASSTHRU_DIRS+= ${TMPDIR}

GOROOT_FINAL=		${PREFIX}/go${GOVERSSUFFIX}
INSTALLATION_DIRS=	bin go${GOVERSSUFFIX}

REPLACE_BASH+=	lib/time/update.bash
REPLACE_BASH+=	misc/arm/a
REPLACE_BASH+=	misc/cgo/fortran/test.bash
REPLACE_BASH+=	misc/wasm/go_js_wasm_exec
REPLACE_BASH+=	src/all.bash
REPLACE_BASH+=	src/bootstrap.bash
REPLACE_BASH+=	src/buildall.bash
REPLACE_BASH+=	src/clean.bash
REPLACE_BASH+=	src/cmd/compile/internal/ssa/gen/cover.bash
REPLACE_BASH+=	src/cmd/go/mkalldocs.sh
REPLACE_BASH+=	src/cmd/vendor/golang.org/x/sys/unix/mkall.sh
REPLACE_BASH+=	src/cmd/vendor/golang.org/x/sys/unix/mkerrors.sh
REPLACE_BASH+=	src/internal/trace/mkcanned.bash
REPLACE_BASH+=	src/make.bash
REPLACE_BASH+=	src/race.bash
REPLACE_BASH+=	src/run.bash
REPLACE_BASH+=	src/syscall/mkall.sh
REPLACE_BASH+=	src/syscall/mkerrors.sh
REPLACE_BASH+=	src/syscall/mksysnum_plan9.sh

REPLACE_PERL+=	src/net/http/cgi/testdata/test.cgi
REPLACE_PERL+=	src/regexp/syntax/make_perl_groups.pl
REPLACE_PERL+=	src/syscall/*.pl

# uses own linker, which does not support relro on NetBSD
CHECK_RELRO_SKIP+=		go${GOVERSSUFFIX}/bin/go
CHECK_RELRO_SKIP+=		go${GOVERSSUFFIX}/bin/gofmt
CHECK_RELRO_SKIP+=		go${GOVERSSUFFIX}/pkg/bootstrap/bin/asm
CHECK_RELRO_SKIP+=		go${GOVERSSUFFIX}/pkg/bootstrap/bin/compile
CHECK_RELRO_SKIP+=		go${GOVERSSUFFIX}/pkg/bootstrap/bin/link
CHECK_RELRO_SKIP+=		go${GOVERSSUFFIX}/pkg/bootstrap/bin/cgo
# also does not support SSP at this time
CHECK_SSP_SKIP=			${CHECK_RELRO_SKIP}

# uses /bin/rc (for Plan 9)
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/include/plan9/mklibc.rc
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/all.rc
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/clean.rc
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/make.rc
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/run.rc

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	src/crypto/x509/root_solaris.go
SUBST_VARS.paths=	PKG_SYSCONFDIR

# Required until we bootstrap from a native illumos kit.  This is obviously
# terrible and should be fixed properly.
.if ${OPSYS} == "SunOS" && ${OS_VARIANT} != "Solaris"
SUBST_CLASSES+=		grplist
SUBST_STAGE.grplist=	pre-configure
SUBST_FILES.grplist=	src/os/user/getgrouplist_unix.go
SUBST_SED.grplist=	-e 's,return getgrouplist.*,return 0;,'
.endif

PLIST_SUBST+=	GOVERSSUFFIX=${GOVERSSUFFIX}

PLIST_VARS+=	pty route

.if ${OPSYS} != "SunOS"
PLIST.pty=	yes
.endif

.if ${OPSYS} != "Linux" && ${OPSYS} != "SunOS"
PLIST.route=	yes
.endif

PRINT_PLIST_AWK+=	/^bin\/go${GOVERSSUFFIX}/ { print "bin/go$${GOVERSSUFFIX}"; next; }
PRINT_PLIST_AWK+=	/^bin\/gofmt${GOVERSSUFFIX}/ { print "bin/gofmt$${GOVERSSUFFIX}"; next; }
PRINT_PLIST_AWK+=	/internal\/pty\.a/ { printf "%s", "$${PLIST.pty}"; }
PRINT_PLIST_AWK+=	/x\/net\/route\.a/ { printf "%s", "$${PLIST.route}"; }

post-extract:
	${RM} -r -f ${WRKSRC}/test/fixedbugs/issue27836*

do-build:
	cd ${WRKSRC}/src && \
		env \
		GOROOT_BOOTSTRAP=${GOROOT_BOOTSTRAP:Q} \
		GOROOT_FINAL=${GOROOT_FINAL:Q} \
		${GOOPT} \
		GOCACHE=${WRKDIR}/.cache/go-build \
		${BASH} ./make.bash
# for RELRO build:
#	cd ${WRKSRC}/src && env GOROOT_BOOTSTRAP=${GOROOT_BOOTSTRAP:Q} GOROOT_FINAL=${GOROOT_FINAL:Q} GO_LDFLAGS="-buildmode=pie" ${GOOPT} ${BASH} ./make.bash

do-install:
	cd ${WRKSRC} && rm -rf pkg/obj pkg/bootstrap
	cd ${WRKSRC} && pax -rw . ${DESTDIR}${PREFIX}/go${GOVERSSUFFIX}
	find ${DESTDIR}${PREFIX}/go${GOVERSSUFFIX} -name \*.orig -exec rm {} \;
.for cmd in go gofmt
	${LN} -sf ${PREFIX}/go${GOVERSSUFFIX}/bin/${cmd} ${DESTDIR}${PREFIX}/bin/${cmd}${GOVERSSUFFIX}
.endfor

do-test:
	cd ${WRKSRC}/src && GOROOT=${WRKSRC} PATH=${WRKSRC}/bin:${PATH} ${GOOPT} ${BASH} run.bash --no-rebuild --banner ""

.include "../../mk/bsd.pkg.mk"
