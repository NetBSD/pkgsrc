# $NetBSD: Makefile,v 1.12 2009/12/27 18:08:12 jakllsch Exp $
#

# Note -- version number also in the do-install rule
MAJVER=4
MINVER=00

DISTNAME=		memtest86+-${MAJVER}.${MINVER}
PKGNAME=		memtestplus-${MAJVER}.${MINVER}
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://www.memtest.org/download/${MAJVER}.${MINVER}/

MAINTAINER=		smb@NetBSD.org
HOMEPAGE=		http://www.memtest.org/
COMMENT=		Thorough, stand alone memory test for x86 arch
LICENSE=		gnu-gpl-v2

ONLY_FOR_PLATFORM=	NetBSD-*-i386 Linux-*-i386 NetBSD-*-x86_64 Linux-*-x86_64

USE_TOOLS+=		gmake
SUBST_CLASSES+=		delcr
SUBST_STAGE.delcr=	post-build
SUBST_MESSAGE.delcr=	Deleting CRs
SUBST_FILES.delcr=	README
SUBST_SED.delcr=	-e 's/.$$//g'

PKG_DESTDIR_SUPPORT=	user-destdir

.include "options.mk"

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-3.*)
BUILDLINK_TRANSFORM+=	rm:-fno-stack-protector
.endif

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/mdec
	${INSTALL_DATA} ${WRKSRC}/memtest.bin \
		${DESTDIR}${PREFIX}/mdec/memtestplus.bin
	${INSTALL_DATA} ${WRKSRC}/memtest ${DESTDIR}${PREFIX}/mdec/memtestplus
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/memtestplus
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/memtestplus
	${INSTALL_DATA} ${WRKSRC}/FAQ ${DESTDIR}${PREFIX}/share/doc/memtestplus
.if !empty(PKG_OPTIONS:Miso)
	${INSTALL_DATA} ${WRKSRC}/mt${MAJVER}${MINVER}.iso \
		${DESTDIR}${PREFIX}/mdec/memtestplus.iso
.endif

.include "../../mk/bsd.pkg.mk"
