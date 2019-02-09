# $NetBSD: Makefile,v 1.27 2019/02/09 09:13:24 maya Exp $
#

# Note -- version number also in the do-install rule
MAJVER=5
MINVER=01

DISTNAME=		memtest86+-${MAJVER}.${MINVER}
PKGNAME=		memtestplus-${MAJVER}.${MINVER}
PKGREVISION=		6
CATEGORIES=		sysutils
MASTER_SITES=		http://www.memtest.org/download/${MAJVER}.${MINVER}/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.memtest.org/
COMMENT=		Thorough, stand alone memory test for x86 arch
LICENSE=		gnu-gpl-v2

ONLY_FOR_PLATFORM=	NetBSD-*-i386 Linux-*-i386 NetBSD-*-x86_64 Linux-*-x86_64

FORTIFY_SUPPORTED=	no
SSP_SUPPORTED=		no

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=		gmake
SUBST_CLASSES+=		delcr
SUBST_STAGE.delcr=	pre-patch
SUBST_MESSAGE.delcr=	Deleting CRs
SUBST_FILES.delcr=	README
SUBST_SED.delcr=	-e 's/.$$//g'

.include "options.mk"

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
BROKEN+=	${PKGNAME} does not produce a working binary with clang
.endif

pre-configure:
	${CP} ${FILESDIR}/io.h ${WRKSRC}

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
