# $NetBSD: Makefile,v 1.20 2024/03/20 15:41:01 adam Exp $

VERS=		3.9.19
DISTNAME=	python-${VERS}-docs-html
PKGNAME=	py39-html-docs-${VERS}
CATEGORIES=	lang python
MASTER_SITES=	https://www.python.org/ftp/python/doc/${VERS}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://www.python.org/doc/
COMMENT=	HTML Documentation for Python 3.9
LICENSE=	python-software-foundation

USE_TOOLS+=	pax

NO_CONFIGURE=	yes
NO_BUILD=	yes

HTMLDIR=	share/doc/python3.9

INSTALLATION_DIRS=	${HTMLDIR}

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
