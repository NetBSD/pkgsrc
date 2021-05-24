# $NetBSD: Makefile,v 1.30 2021/05/24 19:54:10 wiz Exp $

# Track upstream's HEAD
PKG_DATE=	20201004
GIT_COMMIT=	9cba52b9626413307b994af44695b8a9c0e058be
DISTNAME=	i2c-tools-${GIT_COMMIT}
PKGNAME=	decode-dimms-4.2.${PKG_DATE}
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
SUBST_STAGE.rev=	post-extract
SUBST_FILES.rev=	eeprom/decode-dimms
SUBST_SED.rev=		-e '/I2C_TOOLS_VER/s/4.2/4.2-${PKG_DATE}/'

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
