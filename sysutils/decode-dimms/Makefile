# $NetBSD: Makefile,v 1.12 2019/01/17 05:41:10 pgoyette Exp $

# no Release yet
GIT_COMMIT=	4d476eb716c388d3c78e434b5e401e893067ab98
DISTNAME=	i2c-tools-${GIT_COMMIT}
PKGNAME=	decode-dimms-0.0.20190109
CATEGORIES=	sysutils
MASTER_SITES=	https://git.kernel.org/pub/scm/utils/i2c-tools/i2c-tools.git/snapshot/

MAINTAINER=	pgoyette@NetBSD.org
HOMEPAGE=	https://git.kernel.org/pub/scm/utils/i2c-tools/
COMMENT=	Decode memory DIMM SPD ROM info
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	perl:run
REPLACE_PERL=	eeprom/decode-dimms

SUBST_CLASSES+=		rev
SUBST_STAGE.rev=	pre-patch
SUBST_FILES.rev=        eeprom/decode-dimms
SUBST_SED.rev=          -e 's/^$$revision = .*;/$$revision = "20190109-${GIT_COMMIT}";/'
SUBST_SED.rev+=		-e '/^$$revision =~/d'

NO_BUILD=	yes

USE_LANGUAGES=	# empty

ONLY_FOR_PLATFORM= NetBSD-*-*

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/eeprom/decode-dimms \
		${DESTDIR}${PREFIX}/bin/decode-dimms
	${INSTALL_MAN} ${WRKSRC}/eeprom/decode-dimms.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/decode-dimms.1

.include "../../mk/bsd.pkg.mk"
