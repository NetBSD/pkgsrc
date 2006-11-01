# $NetBSD: Makefile,v 1.2 2006/11/01 15:38:15 mlelstv Exp $
#

DISTNAME=		memtest86+-1.65
PKGNAME=		memtestplus-1.65
PKGREVISION=            2
CATEGORIES=		sysutils
MASTER_SITES=		http://www.memtest.org/download/1.65/

MAINTAINER=		smb@NetBSD.org
HOMEPAGE=		http://www.memtest.org/
COMMENT=		Thorough, stand alone memory test for x86 arch

ONLY_FOR_PLATFORM=	NetBSD-*-i386 Linux-*-i386

USE_TOOLS+=		gmake

SUBST_CLASSES+=		delcr
SUBST_STAGE.delcr=	post-build
SUBST_MESSAGE.delcr=	Deleting CRs
SUBST_FILES.delcr=	README
SUBST_SED.delcr=	-e 's/.$$//g'

.include "options.mk"

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/mdec
	${INSTALL_DATA} ${WRKSRC}/memtest.bin ${PREFIX}/mdec/memtestplus.bin
	${INSTALL_DATA} ${WRKSRC}/memtest ${PREFIX}/mdec/memtestplus
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/memtestplus
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/memtestplus
	${INSTALL_DATA} ${WRKSRC}/FAQ ${PREFIX}/share/doc/memtestplus
.if !empty(PKG_OPTIONS:Mmemtesplus-iso)
	${INSTALL_DATA} ${WRKSRC}/memtest.iso ${PREFIX}/mdec/memtestplus.iso
.endif

.include "../../devel/binutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
