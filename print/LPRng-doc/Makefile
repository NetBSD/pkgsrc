# $NetBSD: Makefile,v 1.16 2008/05/26 02:13:23 joerg Exp $

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

do-install:
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/doc/LPRng
	cd ${WRKDIR:Q} && \
	    pax -O -zrf ${DISTDIR:Q}/${DISTNAME:Q}${EXTRACT_SUFX:Q}
	cd ${WRKSRC:Q} && \
	    pax -rw *.dvi *.gif *.html *.ps *.txt ${PREFIX:Q}/share/doc/LPRng

.include "../../mk/bsd.pkg.mk"
