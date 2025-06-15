# $NetBSD: Makefile,v 1.34 2025/06/15 23:45:54 pgoyette Exp $

# Track upstream's HEAD
PKG_DATE=	20241010
GIT_COMMIT=	c20cd0b4be78e7b84104452b7fc9c570f00f92bf
DISTNAME=	i2c-tools-${GIT_COMMIT}
PKGNAME=	decode-dimms-4.4.${PKG_DATE}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://git.kernel.org/pub/scm/utils/i2c-tools/i2c-tools.git/snapshot/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.kernel.org/pub/scm/utils/i2c-tools/
COMMENT=	Decode memory DIMM SPD ROM info
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	perl:run
REPLACE_PERL=	eeprom/decode-dimms

SUBST_CLASSES+=		rev
SUBST_STAGE.rev=	post-patch
SUBST_FILES.rev=	eeprom/decode-dimms
SUBST_SED.rev=		-e '/I2C_TOOLS_VER/s/4.4/4.4-${PKG_DATE}/'

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
