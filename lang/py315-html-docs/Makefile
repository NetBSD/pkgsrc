# $NetBSD: Makefile,v 1.3 2026/10/26 05:37:44 adam Exp $

VERS=		3.15.2
DISTNAME=	python-${VERS}-docs-html
PKGNAME=	py315-html-docs-${VERS}
CATEGORIES=	lang python
MASTER_SITES=	https://www.python.org/ftp/python/doc/${VERS}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.python.org/doc/
COMMENT=	HTML documentation for Python 3.15
LICENSE=	python-software-foundation

USE_TOOLS+=	pax

NO_CONFIGURE=	yes
NO_BUILD=	yes

HTMLDIR=	share/doc/python3.15

INSTALLATION_DIRS=	${HTMLDIR}

post-extract:
	${FIND} ${WRKSRC} -type d -exec chmod go+rx {} \;
	${FIND} ${WRKSRC} -type f -exec chmod go+r {} \;

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
