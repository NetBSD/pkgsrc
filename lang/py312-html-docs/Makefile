# $NetBSD: Makefile,v 1.8 2024/10/03 09:44:50 adam Exp $

VERS=		3.12.7
DISTNAME=	python-${VERS}-docs-html
PKGNAME=	py312-html-docs-${VERS}
CATEGORIES=	lang python
MASTER_SITES=	https://www.python.org/ftp/python/doc/${VERS}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://www.python.org/doc/
COMMENT=	HTML documentation for Python 3.12
LICENSE=	python-software-foundation

WRKSRC=		${WRKDIR}/python-3.12-docs-html

USE_TOOLS+=	pax

NO_CONFIGURE=	yes
NO_BUILD=	yes

HTMLDIR=	share/doc/python3.12

INSTALLATION_DIRS=	${HTMLDIR}

post-extract:
	${FIND} ${WRKSRC} -type d -exec chmod go+rx {} \;
	${FIND} ${WRKSRC} -type f -exec chmod go+r {} \;

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
