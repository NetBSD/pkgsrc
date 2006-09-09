# $NetBSD: Makefile,v 1.8 2006/09/09 02:41:58 obache Exp $
#

DISTNAME=		uno_v28
PKGNAME=		uno-2.8
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://spinroot.com/uno/

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://spinroot.com/uno/
COMMENT=		Tool for source code analysis

WRKSRC=			${WRKDIR}/Uno/src
MAKE_FILE=		makefile

USE_TOOLS+=		bison

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
BUILDLINK_TRANSFORM+=	rm:-m32
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uno ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/uno_local ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/uno_global ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/uno
	${INSTALL_DATA} ${WRKDIR}/Uno/doc/uno_long.pdf ${PREFIX}/share/doc/uno
	${INSTALL_DATA} ${WRKDIR}/Uno/doc/uno_man.pdf ${PREFIX}/share/doc/uno
	${INSTALL_DATA} ${WRKDIR}/Uno/doc/uno_manpage.pdf ${PREFIX}/share/doc/uno
	${INSTALL_DATA} ${WRKDIR}/Uno/doc/uno_short.pdf ${PREFIX}/share/doc/uno
	${INSTALL_MAN} ${WRKDIR}/Uno/doc/uno.1 ${PREFIX}/man/man1

USE_TOOLS+=	bison gmake flex

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	makefile
SUBST_SED.prefix=	-e "s,/usr/bin,${PREFIX}/bin,g"
SUBST_MESSAGE.prefix=	Fixing hardcoded paths.

.include "../../mk/bsd.pkg.mk"
