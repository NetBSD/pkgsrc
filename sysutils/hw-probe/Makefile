# $NetBSD: Makefile,v 1.12 2025/01/13 19:20:34 vins Exp $

DISTNAME=	hw-probe-1.6.6
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_GITHUB:=linuxhw/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://bsd-hardware.info/
#HOMEPAGE+=	https://linux-hardware.org/
COMMENT=	Check operability of computer hardware and find drivers
LICENSE=	gnu-lgpl-v2.1 OR original-bsd

ONLY_FOR_PLATFORM+=	FreeBSD-*-* OpenBSD-*-* NetBSD-*-*
ONLY_FOR_PLATFORM+=	DragonFly-*-* Linux-*-*

USE_TOOLS+=	perl:run

DEPENDS+=	usbutil-[0-9]*:../../sysutils/usbutil
DEPENDS+=	smartmontools-[0-9]*:../../sysutils/smartmontools

CHECK_BUILTIN.openssl:= yes
.include "../../security/openssl/buildlink3.mk"
CHECK_BUILTIN.openssl:= no
.if ${USE_BUILTIN.openssl:U:tl} != yes
DEPENDS+=
mozilla-rootcerts-[0-9]*:../../security/mozilla-rootcerts
.endif

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "x86_64") || (${MACHINE_ARCH} == "aarch64")
DEPENDS+=	dmidecode-[0-9]*:../../sysutils/dmidecode
.endif

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "x86_64")
.  if ${OPSYS:M*BSD} || ${OPSYS} == "DragonFly"
DEPENDS+=	lscpu-[0-9]*:../../sysutils/lscpu
.  else
DEPENDS+=	cpuid-[0-9]*:../../sysutils/cpuid
.  endif
.endif

.if ${OPSYS:M*BSD} || ${OPSYS} == "DragonFly"
SUBST_CLASSES+=		fetch
SUBST_STAGE.fetch=	pre-configure
SUBST_MESSAGE.fetch=	Using bsdfetch on *BSD.
SUBST_FILES.fetch=	hw-probe.pl
SUBST_SED.fetch+=	-e 's|neofetch|bsdfetch|g'

DEPENDS+=	bsdfetch-[0-9]*:../../sysutils/bsdfetch
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
