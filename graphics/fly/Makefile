# $NetBSD: Makefile,v 1.8 1999/08/27 10:11:01 agc Exp $
#

DISTNAME=	fly-1.6.5
CATEGORIES=	graphics www
MASTER_SITES=	ftp://www.unimelb.edu.au/pub/www/tools/unix/fly/

MAINTAINER=	bouyer@netbsd.org
HOMEPAGE=	http://www.unimelb.edu.au/fly/fly.html

DEPENDS+=	gd-1.6.3:../../graphics/gd
BUILD_DEPENDS+=	${LOCALBASE}/bin/giftopnm:../../graphics/netpbm

do-install:
	${MKDIR} ${PREFIX}/share/doc/fly
	${MKDIR} ${PREFIX}/share/examples/fly
	${INSTALL_PROGRAM} ${WRKSRC}/fly ${PREFIX}/bin
	for f in example fly-logo nav-copyright nav-docs nav-feedback	\
					nav-home new valid_html; do	\
		${LOCALBASE}/bin/giftopnm < ${WRKSRC}/doc/$$f.gif |	\
			${LOCALBASE}/bin/pnmtopng > ${PREFIX}/share/doc/fly/$$f.png; \
	done
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/fly
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/fly

.include "../../mk/bsd.pkg.mk"
