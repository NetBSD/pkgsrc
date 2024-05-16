# $NetBSD: Makefile,v 1.7 2024/05/16 06:15:34 wiz Exp $

PKGVER=		1.6.5_20230812
DISTNAME=	hw-probe-${PKGVER}
PKGREVISION=	4
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_GITHUB:=linuxhw/}
GITHUB_TAG=	b895b77b7e03f4b1b0a5fb177118373ee0328a25

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://bsd-hardware.info/
#HOMEPAGE+=	https://linux-hardware.org/
COMMENT=	Check operability of computer hardware and find drivers
LICENSE=	gnu-lgpl-v2.1 OR original-bsd

ONLY_FOR_PLATFORM+=	FreeBSD-*-* OpenBSD-*-* NetBSD-*-*
ONLY_FOR_PLATFORM+=	DragonFly-*-* Linux-*-*

USE_TOOLS+=	perl:run

DEPENDS+=	usbutil-[0-9]*:../../sysutils/usbutil
DEPENDS+=	mozilla-rootcerts-[0-9]*:../../security/mozilla-rootcerts
DEPENDS+=	smartmontools-[0-9]*:../../sysutils/smartmontools

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "x86_64") || (${MACHINE_ARCH} == "aarch64")
DEPENDS+=	dmidecode-[0-9]*:../../sysutils/dmidecode
.endif

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "x86_64")
.  if ${OPSYS} == "NetBSD" || ${OPSYS} == "Linux"
DEPENDS+=	cpuid-[0-9]*:../../sysutils/cpuid
.  else
DEPENDS+=	lscpu-[0-9]*:../../sysutils/lscpu
.  endif
.endif

DOCDIR=		share/doc/${PKGBASE}
MESSAGE_SUBST+=	DOCDIR=${DOCDIR:Q}

REPLACE_PERL+=	hw-probe.pl

NO_BUILD=	yes

INSTALLATION_DIRS+=	bin ${DOCDIR}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/hw-probe.pl		\
		${DESTDIR}${PREFIX}/bin/hw-probe

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md		\
		${DESTDIR}${PREFIX}/${DOCDIR}/README

.include "../../sysutils/pciutils/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
