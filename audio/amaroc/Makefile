# $NetBSD: Makefile,v 1.13 2017/08/01 14:58:51 wiz Exp $
#

DISTNAME=		amaroc-0.3
PKGREVISION=		5
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=amaroc/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://sourceforge.net/projects/amaroc/
COMMENT=		Command line interface to Amarok
LICENSE=		gnu-gpl-v2

DEPENDS+=		${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses

INSTALLATION_DIRS=	bin share/doc/amaroc
REPLACE_PYTHON=	amaroc.py

NO_BUILD=		yes

USE_LANGUAGES=		# none

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/amaroc.py ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/amaroc
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/amaroc

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
