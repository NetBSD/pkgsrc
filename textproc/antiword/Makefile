# $NetBSD: Makefile,v 1.6 2001/10/17 08:43:25 lukem Exp $
#

DISTNAME=	antiword-0.32
WRKSRC=		${WRKDIR}/${DISTNAME:S/-/./}
CATEGORIES=	textproc print
MASTER_SITES=	http://www.winfield.demon.nl/linux/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.winfield.demon.nl/index.html
COMMENT=	free converter MS Word to text and Postscript converter

post-patch:
	cd ${WRKSRC} ; \
	    ${MV} antiword.h antiword.h.orig ; \
	    ${SED} -e "s|@@ANTIWORD_DIR@@|${PREFIX}/share/antiword|g" \
		antiword.h.orig > antiword.h

.include "../../mk/bsd.pkg.mk"
