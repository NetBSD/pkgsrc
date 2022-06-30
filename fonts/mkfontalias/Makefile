# $NetBSD: Makefile,v 1.21 2022/06/30 11:18:24 nia Exp $
#

DISTNAME=	mkfontalias.py
PKGNAME=	mkfontalias-20000521
PKGREVISION=	9
CATEGORIES=	fonts
MASTER_SITES=	http://home.c2i.net/dark/
EXTRACT_SUFX=	# empty

MAINTAINER=	rxg@NetBSD.org
#HOMEPAGE=	http://home.c2i.net/dark/linux.html#fuzzy
COMMENT=	Creates a fonts.alias from the fonts.dir for TrueType fonts

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
NO_BUILD=	yes

REPLACE_PYTHON=		${DISTNAME}
INSTALLATION_DIRS=	bin

PYTHON_VERSIONS_ACCEPTED=	27

do-extract:
	${CP} ${_DISTDIR}/${DISTNAME} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mkfontalias.py \
		${DESTDIR}${PREFIX}/bin/mkfontalias

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
