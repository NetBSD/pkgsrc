# $NetBSD: Makefile,v 1.15 2003/11/12 03:39:42 jschauma Exp $
#

DISTNAME=	suck-4.3.2
PKGREVISION=	1
CATEGORIES=	news
MASTER_SITES=	http://www.sucknews.org/ \
		${MASTER_SITE_SUNSITE:=system/news/transport/} \
		ftp://tsx-11.mit.edu/pub/linux/sources/sbin/

MAINTAINER=	drankin@bohemians.lexington.ky.us
HOMEPAGE=	http://www.sucknews.org/
COMMENT=	Feed a local news server without a dedicated newsfeed

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes

.include "../../mk/bsd.prefs.mk"

# Include SOCKS firewall support
.if defined(USE_SOCKS) && (${USE_SOCKS} == 4 || ${USE_SOCKS} == 5)
.if ${USE_SOCKS} == 4
.include "../../net/socks4/buildlink2.mk"
.else
.include "../../net/socks5/buildlink2.mk"
.endif
.endif

post-patch:
	${SED} -e 's|%%%HISTORY%%%|${LOCALBASE}/etc/news/history|g' \
		${WRKSRC}/Makefile.in >${WRKSRC}/Makefile.tmp
	@${MV} ${WRKSRC}/Makefile.tmp ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA_DIR} ${LOCALBASE}/share/examples/suck
	${CP} ${WRKSRC}/sample/* ${LOCALBASE}/share/examples/suck
	${CHMOD} 644 ${LOCALBASE}/share/examples/suck/*

#.include "../../databases/gdbm/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
