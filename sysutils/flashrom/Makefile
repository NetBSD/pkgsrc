# $NetBSD: Makefile,v 1.7 2013/12/09 18:54:24 jakllsch Exp $
#

DISTNAME=	flashrom-0.9.7
PKGNAME=	${DISTNAME:S/-r/pre/}
CATEGORIES=	sysutils
MASTER_SITES=	http://download.flashrom.org/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jakllsch@NetBSD.org
HOMEPAGE=	http://www.flashrom.org/
COMMENT=	Universal (coreboot/LinuxBIOS) flash utility
LICENSE=        gnu-gpl-v2

USE_TOOLS+= gmake pkg-config

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
DEPENDS+=	dmidecode-[0-9]*:../../sysutils/dmidecode
.endif

.if ${OPSYS} == "NetBSD"

SUBST_CLASSES+=	pciutils
SUBST_FILES.pciutils=	Makefile
SUBST_FILES.pciutils+=	hwaccess.h
SUBST_MESSAGE.pciutils=	adjusting pciutils headers
SUBST_STAGE.pciutils=	pre-configure
SUBST_SED.pciutils+= -e 's,<pci/pci.h>,<pciutils/pci.h>,g'

LDFLAGS+= -lpci
CPPFLAGS+= -I/${PREFIX}/include

.endif

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flashrom ${DESTDIR}${PREFIX}/sbin/flashrom
	${INSTALL_MAN} ${WRKSRC}/flashrom.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/flashrom.8

.include "../../devel/libftdi/buildlink3.mk"
.include "../../sysutils/pciutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
