# $NetBSD: Makefile,v 1.1 2023/10/02 20:07:15 adam Exp $

VERS=		3.12.0
DISTNAME=	python-${VERS}-docs-html
PKGNAME=	py312-html-docs-${VERS}
CATEGORIES=	lang python
MASTER_SITES=	https://www.python.org/ftp/python/doc/${VERS}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://www.python.org/doc/
COMMENT=	HTML documentation for Python 3.12
LICENSE=	python-software-foundation

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
