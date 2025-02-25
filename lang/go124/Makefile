# $NetBSD: Makefile,v 1.1 2025/02/25 20:09:16 bsiegert Exp $

.include "../../lang/go/version.mk"
GO_BOOTSTRAP_REQD=	122
.include "../../lang/go/bootstrap.mk"

GOVERSSUFFIX=	124

DISTNAME=	go${GO${GOVERSSUFFIX}_VERSION}.src
PKGNAME=	go${GOVERSSUFFIX}-${GO${GOVERSSUFFIX}_VERSION}
CATEGORIES=	lang
MASTER_SITES=	https://storage.googleapis.com/golang/

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://golang.org/
COMMENT=	The Go programming language
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/go
USE_TOOLS+=	bash perl pax

# cgo compiles under TMPDIR
TMPDIR?=	/tmp
BUILDLINK_PASSTHRU_DIRS+= ${TMPDIR}

INSTALLATION_DIRS=	bin go${GOVERSSUFFIX}

# These are scripts for upstream developers which are simply installed
# as part of all the golang source code, but are not used at runtime.
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/lib/time/update.bash
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/lib/wasm/go_js_wasm_exec
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/lib/wasm/go_wasip1_wasm_exec
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/all.bash
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/bootstrap.bash
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/buildall.bash
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/clean.bash
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/cmd/compile/internal/ssa/_gen/cover.bash
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/cmd/vendor/golang.org/x/sys/plan9/mkall.sh
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/cmd/vendor/golang.org/x/sys/plan9/mkerrors.sh
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/cmd/vendor/golang.org/x/sys/unix/mkall.sh
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/cmd/vendor/golang.org/x/sys/unix/mkerrors.sh
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/cmd/vendor/golang.org/x/sys/windows/mkerrors.bash
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/cmd/vendor/golang.org/x/sys/windows/mkknownfolderids.bash
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/crypto/internal/boring/build.sh
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/crypto/internal/boring/build-boring.sh
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/crypto/internal/boring/build-goboring.sh
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/go/doc/comment/mkstd.sh
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/cmp.bash
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/make.bash
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/race.bash
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/run.bash
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/runtime/race/mkcgo.sh
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/syscall/mkall.sh
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/syscall/mkerrors.sh
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/syscall/mksysnum_plan9.sh

CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/regexp/syntax/make_perl_groups.pl
CHECK_INTERPRETER_SKIP+=	go${GOVERSSUFFIX}/src/syscall/*.pl

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

PRINT_PLIST_AWK+=	/^bin\/go${GOVERSSUFFIX}/ { print "bin/go$${GOVERSSUFFIX}"; next; }
PRINT_PLIST_AWK+=	/^bin\/gofmt${GOVERSSUFFIX}/ { print "bin/gofmt$${GOVERSSUFFIX}"; next; }

post-extract:
	${RM} -r -f ${WRKSRC}/test/fixedbugs/issue27836*

do-build:
	cd ${WRKSRC}/src && \
		env \
		GOROOT_BOOTSTRAP=${GOROOT_BOOTSTRAP:Q} \
		${GOOPT} \
		GOCACHE=${WRKDIR}/.cache/go-build \
		${BASH} ./make.bash -v
# for RELRO build:
#	cd ${WRKSRC}/src && env GOROOT_BOOTSTRAP=${GOROOT_BOOTSTRAP:Q} GO_LDFLAGS="-buildmode=pie" ${GOOPT} ${BASH} ./make.bash

do-install:
	cd ${WRKSRC} && rm -rf pkg/obj pkg/bootstrap
	cd ${WRKSRC} && pax -rw . ${DESTDIR}${PREFIX}/go${GOVERSSUFFIX}
	find ${DESTDIR}${PREFIX}/go${GOVERSSUFFIX} -name \*.orig -exec rm {} \;
.if ${USE_CROSS_COMPILE:tl} == "yes"
	cd ${DESTDIR}${PREFIX}/go${GOVERSSUFFIX} && \
	${RM} -rf pkg/tool/${NATIVE_GO_PLATFORM}
.endif
.for cmd in go gofmt
.  if ${USE_CROSS_COMPILE:tl} == "yes"
	${MV} ${DESTDIR}${PREFIX}/go${GOVERSSUFFIX}/bin/${GO_PLATFORM}/${cmd} \
		${DESTDIR}${PREFIX}/go${GOVERSSUFFIX}/bin/${cmd}
.  endif
	${LN} -sf ${PREFIX}/go${GOVERSSUFFIX}/bin/${cmd} ${DESTDIR}${PREFIX}/bin/${cmd}${GOVERSSUFFIX}
.endfor

do-test:
	cd ${WRKSRC}/src && GOROOT=${WRKSRC} PATH=${WRKSRC}/bin:${PATH} ${GOOPT} ${BASH} run.bash --no-rebuild --banner ""

.include "../../mk/bsd.pkg.mk"
