# $NetBSD: Makefile,v 1.1 1998/04/28 11:05:52 frueauf Exp $
#

DISTNAME=	suck-3.9.3
CATEGORIES=	news
MASTER_SITES=	http://home.att.net/~bobyetman/
MASTER_SITES+=	ftp://sunsite.unc.edu/pub/Linux/system/news/transport/
MASTER_SITES+=	ftp://tsx-11.mit.edu/pub/linux/sources/sbin/

MAINTAINER=	root@garbled.net

HAS_CONFIGURE=	yes
CONFIGURE_ARGS= --prefix=${LOCALBASE}

MAN1=		rpost.1 suck.1 testhost.1 lmove.1

post-patch:
	@${CAT} ${WRKSRC}/Makefile.in | ${SED} \
		-e 's+%%%HISTORY%%%+'${LOCALBASE}'/etc/news/history+g' \
		>${WRKSRC}/Makefile.tmp
	@${MV} ${WRKSRC}/Makefile.tmp ${WRKSRC}/Makefile.in

post-install:
	${MKDIR} ${LOCALBASE}/share/examples/suck
	${CP} ${WRKSRC}/sample/* ${LOCALBASE}/share/examples/suck

.include "../../mk/bsd.pkg.mk"
