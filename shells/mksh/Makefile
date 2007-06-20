# $NetBSD: Makefile,v 1.4 2007/06/20 17:20:45 joerg Exp $

DISTNAME=			mksh-R29f
PKGNAME=			mksh-29.6
CATEGORIES=			shells
MASTER_SITES=			http://www.mirbsd.org/MirOS/dist/mir/mksh/ \
				http://pub.allbsd.org/MirOS/dist/mir/mksh/
EXTRACT_SUFX=			.cpio.gz

MAINTAINER=			pkgsrc-users@NetBSD.org
HOMEPAGE=			http://mirbsd.de/mksh
COMMENT=			MirBSD Korn Shell

WRKSRC=				${WRKDIR}/mksh
WRKBUILD?=			${WRKSRC}

PKG_INSTALLATION_TYPES=		pkgviews overwrite
PKG_DESTDIR_SUPPORT=		user-destdir

PKG_SHELL=			bin/mksh

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=		PKG_OPTIONS.mksh
PKG_SUPPORTED_OPTIONS=		static

.include "../../mk/bsd.options.mk"

BUILD_PARMS=			-r	# don't call nRoff

.if empty(PKG_OPTIONS:Mstatic)
BUILD_PARMS+=			-d	# build dynamically linked
.else
BUILD_PARMS+=			-nd	# build statically linked
.endif

LIBS+=				${LDADD}
.if ${OPSYS} == "Interix"
LIBS+=				-lcrypt
.endif

INSTALLATION_DIRS=		bin ${PKGMANDIR}/man1 share/examples/mksh

do-build:
	cd ${WRKBUILD} && LIBS=${LIBS:Q} CC=${CC:Q} CFLAGS=${CFLAGS:Q} \
	    CPPFLAGS=${CPPFLAGS:Q} LDFLAGS=${LDFLAGS:Q} \
	    ${TOOLS_SHELL} ${WRKSRC}/Build.sh ${BUILD_PARMS}

do-install:
	${INSTALL_PROGRAM} ${WRKBUILD}/mksh ${DESTDIR}${PREFIX}/bin/mksh
	${INSTALL_MAN} ${WRKSRC}/mksh.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/dot.mkshrc ${DESTDIR}${PREFIX}/share/examples/mksh/

# comment this out if you do not want to run the regression tests
#USE_TOOLS+=			perl
#do-test:
#	${WRKBUILD}/test.sh -v

.include "../../mk/bsd.pkg.mk"
