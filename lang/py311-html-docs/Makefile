# $NetBSD: Makefile,v 1.10 2024/04/08 12:49:33 adam Exp $

VERS=		3.11.9
DISTNAME=	python-${VERS}-docs-html
PKGNAME=	py311-html-docs-${VERS}
CATEGORIES=	lang python
MASTER_SITES=	https://www.python.org/ftp/python/doc/${VERS}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://www.python.org/doc/
COMMENT=	HTML documentation for Python 3.11
LICENSE=	python-software-foundation

USE_TOOLS+=	pax

NO_CONFIGURE=	yes
NO_BUILD=	yes

HTMLDIR=	share/doc/python3.11

INSTALLATION_DIRS=	${HTMLDIR}

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
