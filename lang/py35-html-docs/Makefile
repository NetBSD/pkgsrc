# $NetBSD: Makefile,v 1.1 2016/07/12 10:13:59 leot Exp $
#

VERS=		3.5.2
DISTNAME=	python-${VERS}-docs-html
PKGNAME=	py35-html-docs-${VERS}
CATEGORIES=	lang python
MASTER_SITES=	https://docs.python.org/${VERS:C/\.[0-9]+$//}/archives/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.python.org/doc/
COMMENT=	HTML Documentation for Python 3.5
LICENSE=	python-software-foundation

DIST_SUBDIR=	python

USE_TOOLS+=	pax

NO_CONFIGURE=	yes
NO_BUILD=	yes

HTMLDIR=	share/doc/python3.5

INSTALLATION_DIRS=	${HTMLDIR}

do-install:
	cd ${WRKSRC} && pax -rw -pp . ${DESTDIR}${PREFIX}/${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
