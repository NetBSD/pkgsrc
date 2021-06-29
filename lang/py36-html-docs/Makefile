# $NetBSD: Makefile,v 1.15 2021/06/29 12:37:47 adam Exp $

VERS=		3.6.14
DISTNAME=	python-${VERS}-docs-html
PKGNAME=	py36-html-docs-${VERS}
CATEGORIES=	lang python
MASTER_SITES=	https://www.python.org/ftp/python/doc/${VERS}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://www.python.org/doc/
COMMENT=	HTML Documentation for Python 3.6
LICENSE=	python-software-foundation

USE_TOOLS+=	pax

NO_CONFIGURE=	yes
NO_BUILD=	yes

HTMLDIR=	share/doc/python3.6

INSTALLATION_DIRS=	${HTMLDIR}

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
