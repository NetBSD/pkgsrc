# $NetBSD: Makefile,v 1.4 2019/03/26 21:29:20 leot Exp $
#

VERS=		3.7.3
DISTNAME=	python-${VERS}-docs-html
PKGNAME=	py37-html-docs-${VERS}
CATEGORIES=	lang python
MASTER_SITES=	https://www.python.org/ftp/python/doc/${VERS}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://www.python.org/doc/
COMMENT=	HTML Documentation for Python 3.7
LICENSE=	python-software-foundation

DIST_SUBDIR=	python

USE_TOOLS+=	pax

NO_CONFIGURE=	yes
NO_BUILD=	yes

HTMLDIR=	share/doc/python3.7

INSTALLATION_DIRS=	${HTMLDIR}

do-install:
	cd ${WRKSRC} && pax -rw -pp . ${DESTDIR}${PREFIX}/${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
