# $NetBSD: Makefile,v 1.15 2006/09/04 08:47:17 martti Exp $

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

do-install:
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/doc/LPRng
	cd ${WRKDIR:Q} && \
	    ${PAX} -O -zrf ${DISTDIR:Q}/${DISTNAME:Q}${EXTRACT_SUFX:Q}
	cd ${WRKSRC:Q} && \
	    ${PAX} -rw *.dvi *.gif *.html *.ps *.txt ${PREFIX:Q}/share/doc/LPRng

.include "../../mk/bsd.pkg.mk"
