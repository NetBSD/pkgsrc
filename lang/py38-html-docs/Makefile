# $NetBSD: Makefile,v 1.1 2019/10/16 11:05:36 leot Exp $

VERS=		3.8.0
DISTNAME=	python-${VERS}-docs-html
PKGNAME=	py38-html-docs-${VERS}
CATEGORIES=	lang python
MASTER_SITES=	https://www.python.org/ftp/python/doc/${VERS}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://www.python.org/doc/
COMMENT=	HTML Documentation for Python 3.8
LICENSE=	python-software-foundation

USE_TOOLS+=	pax

NO_CONFIGURE=	yes
NO_BUILD=	yes

HTMLDIR=	share/doc/python3.8

INSTALLATION_DIRS=	${HTMLDIR}

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
