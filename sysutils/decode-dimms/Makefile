# $NetBSD: Makefile,v 1.32 2022/06/28 11:35:55 wiz Exp $

# Track upstream's HEAD
PKG_DATE=	20210722
GIT_COMMIT=	d8bc1f1ff4b00a6bd988aa114100ae9b787f50d8
DISTNAME=	i2c-tools-${GIT_COMMIT}
PKGNAME=	decode-dimms-4.3.${PKG_DATE}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://git.kernel.org/pub/scm/utils/i2c-tools/i2c-tools.git/snapshot/

MAINTAINER=	pgoyette@NetBSD.org
HOMEPAGE=	https://git.kernel.org/pub/scm/utils/i2c-tools/
COMMENT=	Decode memory DIMM SPD ROM info
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	perl:run
REPLACE_PERL=	eeprom/decode-dimms

SUBST_CLASSES+=		rev
SUBST_STAGE.rev=	post-patch
SUBST_FILES.rev=	eeprom/decode-dimms
SUBST_SED.rev=		-e '/I2C_TOOLS_VER/s/4.3/4.3-${PKG_DATE}/'

NO_BUILD=	yes

USE_LANGUAGES=	# empty

# This package's primary purpose is to introduce use of hw.spdmem* sysctl
# as the source of SPD data; these sysctl variables are only available on
# NetBSD (and only if the spdmem(4) device is configured).
ONLY_FOR_PLATFORM=	NetBSD-*-*

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/eeprom/decode-dimms \
		${DESTDIR}${PREFIX}/bin/decode-dimms
	${INSTALL_MAN} ${WRKSRC}/eeprom/decode-dimms.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/decode-dimms.1

.include "../../mk/bsd.pkg.mk"
