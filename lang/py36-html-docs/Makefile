# $NetBSD: Makefile,v 1.7 2018/07/31 10:12:26 leot Exp $
#

VERS=		3.6.6
DISTNAME=	python-${VERS}-docs-html
PKGNAME=	py36-html-docs-${VERS}
CATEGORIES=	lang python
MASTER_SITES=	https://www.python.org/ftp/python/doc/${VERS}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://www.python.org/doc/
COMMENT=	HTML Documentation for Python 3.6
LICENSE=	python-software-foundation

DIST_SUBDIR=	python

USE_TOOLS+=	pax

NO_CONFIGURE=	yes
NO_BUILD=	yes

HTMLDIR=	share/doc/python3.6

INSTALLATION_DIRS=	${HTMLDIR}

do-install:
	cd ${WRKSRC} && pax -rw -pp . ${DESTDIR}${PREFIX}/${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
