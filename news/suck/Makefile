# $NetBSD: Makefile,v 1.3 1998/08/01 16:59:39 frueauf Exp $
#

DISTNAME=	suck-3.9.4
CATEGORIES=	news
MASTER_SITES=	http://home.att.net/~bobyetman/
MASTER_SITES+=	ftp://sunsite.unc.edu/pub/Linux/system/news/transport/
MASTER_SITES+=	ftp://tsx-11.mit.edu/pub/linux/sources/sbin/

MAINTAINER=	root@garbled.net

CONFLICTS=	suck-3.9.3

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

.include "../../mk/bsd.pkg.mk"
