# $NetBSD: Makefile,v 1.18 2012/10/08 13:45:34 asau Exp $

DISTNAME=	LPRng_DOC-3.6.13
PKGNAME=	LPRng-doc-3.6.13
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.astart.com/pub/LPRng/LPRng/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lprng.com/
COMMENT=	LPRng documentation in dvi, text, html and ps formats

EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_TOOLS+=	pax

INSTALLATION_DIRS=	share/doc/LPRng

do-install:
	cd ${WRKDIR:Q} && \
	    pax -O -zrf ${DISTDIR:Q}/${DISTNAME:Q}${EXTRACT_SUFX:Q}
	cd ${WRKSRC:Q} && \
	    pax -rw *.dvi *.gif *.html *.ps *.txt ${DESTDIR}${PREFIX}/share/doc/LPRng

.include "../../mk/bsd.pkg.mk"
