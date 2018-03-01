# $NetBSD: Makefile,v 1.1 2018/03/01 22:45:58 pgoyette Exp $

DISTNAME=	decode-dimms-20171205
CATEGORIES=	sysutils
#MASTER_SITES=	https://git.kernel.org/pub/scm/utils/i2c-tools/i2c-tools.git/tree/eeprom/decode-dimms

MAINTAINER=	paul@whooppee.com
HOMEPAGE=	https://git.kernel.org/pub/scm/utils/i2c-tools/i2c-tools.git/
COMMENT=	Memory SPD ROM decoder
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_LANGUAGES=	# none

.include "../../mk/bsd.prefs.mk"

REPLACE_PERL+=	decode-dimms

INSTALLATION_DIRS=	bin

do-configure:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/decode-dimms ${DESTDIR}${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
