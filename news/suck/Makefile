# $NetBSD: Makefile,v 1.6 1999/02/20 22:48:38 hubertf Exp $
#

DISTNAME=	suck-3.10.1
CATEGORIES=	news
MASTER_SITES=	http://home.att.net/~bobyetman/
MASTER_SITES+=	ftp://sunsite.unc.edu/pub/Linux/system/news/transport/
MASTER_SITES+=	ftp://tsx-11.mit.edu/pub/linux/sources/sbin/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://home.att.net/~bobyetman/

HAS_CONFIGURE=	yes
CONFIGURE_ARGS= --prefix=${LOCALBASE}

post-patch:
	@${CAT} ${WRKSRC}/Makefile.in | ${SED} \
		-e 's+%%%HISTORY%%%+'${LOCALBASE}'/etc/news/history+g' \
		>${WRKSRC}/Makefile.tmp
	@${MV} ${WRKSRC}/Makefile.tmp ${WRKSRC}/Makefile.in

post-install:
	${MKDIR} ${LOCALBASE}/share/examples/suck
	${CP} ${WRKSRC}/sample/* ${LOCALBASE}/share/examples/suck
	${CHMOD} 644 ${LOCALBASE}/share/examples/suck/*

.include "../../mk/bsd.pkg.mk"
