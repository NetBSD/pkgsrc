# $NetBSD: Makefile,v 1.7 1999/10/21 16:17:04 agc Exp $
#

DISTNAME=	suck-4.2.2
CATEGORIES=	news
MASTER_SITES=	http://home.att.net/~bobyetman/ \
		ftp://sunsite.unc.edu/pub/Linux/system/news/transport/ \
		ftp://tsx-11.mit.edu/pub/linux/sources/sbin/

MAINTAINER=	drankin@bohemians.lexington.ky.us
HOMEPAGE=	http://home.att.net/~bobyetman/

GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

# Include SOCKS firewall support
.if defined(USE_SOCKS) && (${USE_SOCKS} == 4 || ${USE_SOCKS} == 5)
.if ${USE_SOCKS} == 4
DEPENDS+=		socks4-2.2:../../net/socks4
.else
DEPENDS+=		socks5-1.0.2:../../net/socks5
.endif
.endif

post-patch:
	${SED} -e 's|%%%HISTORY%%%|${LOCALBASE}/etc/news/history|g' \
		${WRKSRC}/Makefile.in >${WRKSRC}/Makefile.tmp
	@${MV} ${WRKSRC}/Makefile.tmp ${WRKSRC}/Makefile.in

post-install:
	${MKDIR} ${LOCALBASE}/share/examples/suck
	${CP} ${WRKSRC}/sample/* ${LOCALBASE}/share/examples/suck
	${CHMOD} 644 ${LOCALBASE}/share/examples/suck/*

.include "../../mk/bsd.pkg.mk"
