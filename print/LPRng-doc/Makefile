# $NetBSD: Makefile,v 1.21 2026/01/06 08:51:53 wiz Exp $

DISTNAME=	LPRng_DOC-3.6.13
PKGNAME=	LPRng-doc-3.6.13
CATEGORIES=	print
#MASTER_SITES=	ftp://ftp.astart.com/pub/LPRng/LPRng/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lprng.sourceforge.net/
COMMENT=	LPRng documentation in dvi, text, html and ps formats

EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_TOOLS+=	gzip pax

INSTALLATION_DIRS=	share/doc/LPRng

do-install:
	cd ${WRKDIR:Q} && \
	    pax -O -zrf ${DISTDIR:Q}/${DISTNAME:Q}${EXTRACT_SUFX:Q}
	cd ${WRKSRC:Q} && \
	    pax -rw *.dvi *.gif *.html *.ps *.txt ${DESTDIR}${PREFIX}/share/doc/LPRng

.include "../../mk/bsd.pkg.mk"
