# $NetBSD: Makefile,v 1.3 2003/03/29 12:40:58 jmmv Exp $
#

DISTNAME=	mkfontalias.py
PKGNAME=	mkfontalias-20000521
WRKSRC=		${WRKDIR}
CATEGORIES=	fonts
MASTER_SITES=	http://home.c2i.net/dark/
EXTRACT_SUFX=	# empty

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://home.c2i.net/dark/linux.html#fuzzy
COMMENT=	creates a fonts.alias from the fonts.dir for TrueType fonts

EXTRACT_ONLY=	# empty
NO_BUILD=	yes

PYTHON_PATCH_SCRIPTS=	${DISTNAME}

do-extract:
	${CP} ${_DISTDIR}/${DISTNAME} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mkfontalias.py ${PREFIX}/bin/mkfontalias

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
