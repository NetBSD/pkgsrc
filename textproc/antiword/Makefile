# $NetBSD: Makefile,v 1.7 2001/10/17 08:52:03 lukem Exp $
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
	${SED} -e "s|@@PREFIX@@|${PREFIX}|g" antiword.h.orig > antiword.h ; \
	${MV} Docs/antiword.1 Docs/antiword.1.orig ; \
	${SED} -e "s|@@PREFIX@@|${PREFIX}|g" Docs/antiword.1.orig > \
	    Docs/antiword.1

.include "../../mk/bsd.pkg.mk"
