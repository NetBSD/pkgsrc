# $NetBSD: Makefile,v 1.3 2025/02/04 22:21:19 adam Exp $

VERS=		3.13.2
DISTNAME=	python-${VERS}-docs-html
PKGNAME=	py313-html-docs-${VERS}
CATEGORIES=	lang python
MASTER_SITES=	https://www.python.org/ftp/python/doc/${VERS}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://www.python.org/doc/
COMMENT=	HTML documentation for Python 3.13
LICENSE=	python-software-foundation

USE_TOOLS+=	pax

NO_CONFIGURE=	yes
NO_BUILD=	yes

HTMLDIR=	share/doc/python3.13

INSTALLATION_DIRS=	${HTMLDIR}

post-extract:
	${FIND} ${WRKSRC} -type d -exec chmod go+rx {} \;
	${FIND} ${WRKSRC} -type f -exec chmod go+r {} \;

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
