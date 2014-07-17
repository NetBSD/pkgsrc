# $NetBSD: Makefile,v 1.4 2014/07/17 10:04:45 obache Exp $
#

VERS=		2.7.8
DISTNAME=	python-${VERS}-docs-html
PKGNAME=	py27-html-docs-${VERS}
CATEGORIES=	lang python
MASTER_SITES=	https://www.python.org/ftp/python/doc/${VERS}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.python.org/doc/
COMMENT=	HTML Documentation for Python 2.7

DIST_SUBDIR=	python

USE_TOOLS+=	pax

NO_CONFIGURE=	yes
NO_BUILD=	yes

HTMLDIR=	share/doc/html/python2.7

INSTALLATION_DIRS=	${HTMLDIR}

GENERATE_PLIST=	cd ${DESTDIR}${PREFIX} && ${FIND} ${HTMLDIR} -type f -print;

do-install:
	cd ${WRKSRC} && pax -rw -pp [a-z]* ${DESTDIR}${PREFIX}/${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
