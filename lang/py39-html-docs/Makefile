# $NetBSD: Makefile,v 1.4 2021/04/03 06:23:13 adam Exp $

VERS=		3.9.3
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
