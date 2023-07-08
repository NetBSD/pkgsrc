# $NetBSD: Makefile,v 1.1 2023/07/08 22:15:42 vins Exp $

DISTNAME=	hw-probe
PKGNAME=	hw-probe-1.6
CATEGORIES=	sysutils perl5
MASTER_SITES=	http://bsd-hardware.info/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	# empty

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://bsd-hardware.info/
COMMENT=	Check operability of computer hardware and find drivers
LICENSE=	gnu-lgpl-v2.1 OR original-bsd

ONLY_FOR_PLATFORM+=	FreeBSD-*-* OpenBSD-*-* NetBSD-*-* DragonFly-*-*

DEPENDS+=	curl-[0-9]*:../../www/curl
DEPENDS+=	usbutil-[0-9]*:../../sysutils/usbutil
DEPENDS+=	mozilla-rootcerts-[0-9]*:../../security/mozilla-rootcerts
DEPENDS+=	smartmontools-[0-9]*:../../sysutils/smartmontools

USE_TOOLS+=	perl:run

REPLACE_PERL+=	hw-probe

USE_TOOLS+=	perl:run

INSTALLATION_DIRS+=	bin

NO_BUILD=	yes

WRKSRC=	${WRKDIR}

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "x86_64") || (${MACHINE_ARCH} == "aarch64")
DEPENDS+=	dmidecode-[0-9]*:../../sysutils/dmidecode
.endif

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "x86_64")
.  if ${OPSYS} == "NetBSD"
DEPENDS+=	cpuid-[0-9]*:../../sysutils/cpuid
.  else
DEPENDS+=	lscpu-[0-9]*:../../sysutils/lscpu
.  endif
.endif


do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/hw-probe ${DESTDIR}${PREFIX}/bin/hw-probe

.include "../../mk/bsd.pkg.mk"
