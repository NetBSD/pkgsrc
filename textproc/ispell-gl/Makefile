# $NetBSD: Makefile,v 1.1 2013/04/24 11:45:00 rodent Exp $
#

DISTNAME=	ispell-gl-0.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ispell-gl/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://ispell-gl.sourceforge.net/
COMMENT=	Galician dictionary for interactive spelling checker
LICENSE=	gnu-gpl-v2

DEPENDS+=	ispell>=3.1.20:../../textproc/ispell
USE_LANGUAGES=	# none
NO_CONFIGURE=	yes

INSTALLATION_DIRS+=	lib

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PREFIX}/bin/buildhash galician.words galician.aff \
			galician.hash

do-install:
	${INSTALL_DATA} ${WRKSRC}/galician.aff ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/galician.hash ${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
