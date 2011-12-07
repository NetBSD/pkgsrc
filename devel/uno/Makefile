# $NetBSD: Makefile,v 1.15 2011/12/07 08:19:57 marino Exp $
#

DISTNAME=		uno_v213
PKGNAME=		uno-2.13
CATEGORIES=		devel
MASTER_SITES=		http://spinroot.com/uno/

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://spinroot.com/uno/
COMMENT=		Tool for source code analysis

NOT_FOR_PLATFORM=	DragonFly-*-x86_64	#Cannot build 32-bit binary
WRKSRC=			${WRKDIR}/uno/src
MAKE_FILE=		makefile

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

USE_TOOLS+=		bison gmake flex

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
BUILDLINK_TRANSFORM+=	rm:-m32
.endif

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	makefile
SUBST_SED.prefix=	-e "s,/usr/bin,${PREFIX}/bin,g"
SUBST_MESSAGE.prefix=	Fixing hardcoded paths.

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/uno

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uno ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/uno_local ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/uno_global ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/uno/doc/uno_long.pdf ${DESTDIR}${PREFIX}/share/doc/uno
	${INSTALL_DATA} ${WRKDIR}/uno/doc/uno_man.pdf ${DESTDIR}${PREFIX}/share/doc/uno
	${INSTALL_DATA} ${WRKDIR}/uno/doc/uno_manpage.pdf ${DESTDIR}${PREFIX}/share/doc/uno
	${INSTALL_DATA} ${WRKDIR}/uno/doc/uno_short.pdf ${DESTDIR}${PREFIX}/share/doc/uno
	${INSTALL_MAN} ${WRKDIR}/uno/doc/uno.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
