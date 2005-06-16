# $NetBSD: Makefile,v 1.13 2005/06/16 05:38:00 martti Exp $

DISTNAME=	LPRng_DOC-3.6.13
PKGNAME=	LPRng-doc-3.6.13
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.astart.com/pub/LPRng/LPRng/
EXTRACT_SUFX=	.tgz

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.lprng.com/
COMMENT=	LPRng documentation in dvi, text, html and ps formats

EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/LPRng
	cd ${WRKDIR} && ${PAX} -O -zrf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
	cd ${WRKSRC} && \
	    ${PAX} -rw *.dvi *.gif *.html *.ps *.txt ${PREFIX}/share/doc/LPRng

.include "../../mk/bsd.pkg.mk"
