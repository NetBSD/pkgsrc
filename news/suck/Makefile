# $NetBSD: Makefile,v 1.24 2007/09/06 21:51:53 jlam Exp $
#

DISTNAME=	suck-4.3.2
PKGREVISION=	3
CATEGORIES=	news
MASTER_SITES=	http://home.comcast.net/~bobyetman/ \
		${MASTER_SITE_SUNSITE:=system/news/transport/} \
		ftp://tsx-11.mit.edu/pub/linux/sources/sbin/

MAINTAINER=	drankin@bohemians.lexington.ky.us
HOMEPAGE=	http://home.comcast.net/~bobyetman/
COMMENT=	Feed a local news server without a dedicated newsfeed

GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

post-patch:
	${SED} -e 's|%%%HISTORY%%%|${PREFIX}/etc/news/history|g' \
		${WRKSRC}/Makefile.in >${WRKSRC}/Makefile.tmp
	@${MV} ${WRKSRC}/Makefile.tmp ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/suck
	${CP} ${WRKSRC}/sample/* ${PREFIX}/share/examples/suck
	${CHMOD} 644 ${PREFIX}/share/examples/suck/*

.if !empty(LOWER_OPSYS:Mirix5*)
.  include "../../pkgtools/libnbcompat/inplace.mk"	# snprintf()
.endif
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
