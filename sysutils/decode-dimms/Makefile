# $NetBSD: Makefile,v 1.10 2018/09/27 19:38:46 tnn Exp $

# no Release yet
GIT_COMMIT=	84da8192c7c409f37c1906b60ef166c58aafc847
DISTNAME=	i2c-tools-${GIT_COMMIT}
PKGNAME=	decode-dimms-0.0.20181205
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
SUBST_SED.rev=          -e 's/^$$revision = .*;/$$revision = "20171205-${GIT_COMMIT}";/'
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
