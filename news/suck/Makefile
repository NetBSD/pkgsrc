# $NetBSD: Makefile,v 1.28 2009/06/30 00:07:22 joerg Exp $
#

DISTNAME=	suck-4.3.2
PKGREVISION=	4
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SUNSITE:=system/news/transport/}

MAINTAINER=	drankin@bohemians.lexington.ky.us
HOMEPAGE=	http://home.comcast.net/~bobyetman/
COMMENT=	Feed a local news server without a dedicated newsfeed

GNU_CONFIGURE=	yes
USE_FEATURES=	snprintf

MAKE_JOBS_SAFE=		no

.include "options.mk"

post-patch:
	${SED} -e 's|%%%HISTORY%%%|${PREFIX}/etc/news/history|g' \
		${WRKSRC}/Makefile.in >${WRKSRC}/Makefile.tmp
	@${MV} ${WRKSRC}/Makefile.tmp ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/suck
	${CP} ${WRKSRC}/sample/* ${PREFIX}/share/examples/suck
	${CHMOD} 644 ${PREFIX}/share/examples/suck/*

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
