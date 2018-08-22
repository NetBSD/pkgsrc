# $NetBSD: Makefile,v 1.17 2018/08/22 09:45:20 wiz Exp $

.include "../../lang/go/version.mk"

DISTNAME=	go${GO14_VERSION}.src
PKGNAME=	go14-${GO14_VERSION}
PKGREVISION=	7
CATEGORIES=	lang
MASTER_SITES=	https://storage.googleapis.com/golang/
PATCH_SITES=	https://codereview.appspot.com/download/

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	http://golang.org/
COMMENT=	The Go programming language
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/go
USE_TOOLS+=	bash:run perl:run pax

# uses ulimit -T
BUILD_DEPENDS+=	bash>=4.2nb3:../../shells/bash

# cgo compiles under TMPDIR
TMPDIR?=	/tmp
BUILDLINK_PASSTHRU_DIRS+= ${TMPDIR}

GOROOT_FINAL=	${PREFIX}/go14
INSTALLATION_DIRS= go14

MAKE_ENV+=	GOROOT_FINAL=${GOROOT_FINAL:Q}
MAKE_ENV+=	CGO_ENABLED=0

REPLACE_BASH+=	doc/articles/wiki/test.bash
REPLACE_BASH+=	doc/codewalk/run
REPLACE_BASH+=	doc/progs/run
REPLACE_BASH+=	doc/progs/update.bash
REPLACE_BASH+=	lib/codereview/test.sh
REPLACE_BASH+=	lib/time/update.bash
REPLACE_BASH+=	misc/arm/a
REPLACE_BASH+=	misc/benchcmp
REPLACE_BASH+=	misc/cgo/errors/test.bash
REPLACE_BASH+=	misc/cgo/testcdefs/test.bash
REPLACE_BASH+=	misc/cgo/testgodefs/test.bash
REPLACE_BASH+=	misc/cgo/testso/test.bash
REPLACE_BASH+=	misc/nacl/go_nacl_386_exec
REPLACE_BASH+=	misc/nacl/go_nacl_amd64p32_exec
REPLACE_BASH+=	misc/nacl/go_nacl_arm_exec
REPLACE_BASH+=	src/all.bash
REPLACE_BASH+=	src/androidtest.bash
REPLACE_BASH+=	src/clean.bash
REPLACE_BASH+=	src/cmd/go/mkdoc.sh
REPLACE_BASH+=	src/cmd/go/test.bash
REPLACE_BASH+=	src/make.bash
REPLACE_BASH+=	src/nacltest.bash
REPLACE_BASH+=	src/race.bash
REPLACE_BASH+=	src/run.bash
REPLACE_BASH+=	src/runtime/mknacl.sh
REPLACE_BASH+=	src/sudo.bash
REPLACE_BASH+=	src/syscall/mkall.sh
REPLACE_BASH+=	src/syscall/mkerrors.sh
REPLACE_BASH+=	src/syscall/mksysnum_plan9.sh
REPLACE_BASH+=	test/bench/shootout/timing.sh
REPLACE_BASH+=	test/run

REPLACE_PERL+=	src/net/http/cgi/testdata/test.cgi
REPLACE_PERL+=	src/regexp/syntax/make_perl_groups.pl
REPLACE_PERL+=	src/syscall/*.pl
REPLACE_PERL+=	test/errchk

# uses its own linker which does not support relro in 1.4.x
CHECK_RELRO_SKIP=	go14/bin/go
CHECK_RELRO_SKIP+=	go14/bin/gofmt

# uses /bin/rc (for Plan 9)
CHECK_INTERPRETER_SKIP+=	go14/include/plan9/mklibc.rc
CHECK_INTERPRETER_SKIP+=	go14/src/all.rc
CHECK_INTERPRETER_SKIP+=	go14/src/clean.rc
CHECK_INTERPRETER_SKIP+=	go14/src/make.rc
CHECK_INTERPRETER_SKIP+=	go14/src/run.rc

do-build:
	cd ${WRKSRC}/src && ${PKGSRC_SETENV} ${MAKE_ENV}  ${GOOPT} ${BASH} ./make.bash

do-install:
	cd ${WRKSRC} && rm -rf .hgignore .hgtags pkg/obj
	cd ${WRKDIR}/go && pax -rw * ${DESTDIR}${GOROOT_FINAL}
	find ${DESTDIR}${GOROOT_FINAL} -name \*.orig -exec rm {} \;

.include "../../mk/bsd.pkg.mk"
