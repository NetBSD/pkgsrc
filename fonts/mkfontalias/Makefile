# $NetBSD: Makefile,v 1.4 2003/07/17 21:37:26 grant Exp $
#

DISTNAME=	mkfontalias.py
PKGNAME=	mkfontalias-20000521
WRKSRC=		${WRKDIR}
CATEGORIES=	fonts
MASTER_SITES=	http://home.c2i.net/dark/
EXTRACT_SUFX=	# empty

MAINTAINER=	rxg@NetBSD.org
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
