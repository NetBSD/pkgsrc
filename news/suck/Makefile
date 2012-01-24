# $NetBSD: Makefile,v 1.32 2012/01/24 09:11:13 sbd Exp $
#

DISTNAME=	suck-4.3.2
PKGREVISION=	7
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SUNSITE:=system/news/transport/}

MAINTAINER=	drankin@bohemians.lexington.ky.us
HOMEPAGE=	http://home.comcast.net/~bobyetman/
COMMENT=	Feed a local news server without a dedicated newsfeed

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_FEATURES=	snprintf

MAKE_JOBS_SAFE=		no

.include "options.mk"

post-patch:
	${SED} -e 's|%%%HISTORY%%%|${PREFIX}/etc/news/history|g' \
		${WRKSRC}/Makefile.in >${WRKSRC}/Makefile.tmp
	@${MV} ${WRKSRC}/Makefile.tmp ${WRKSRC}/Makefile.in

INSTALLATION_DIRS+=	share/examples/suck
INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA} ${WRKSRC}/sample/* ${DESTDIR}${PREFIX}/share/examples/suck

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
.include "../../databases/gdbm_compat/buildlink3.mk"
.endif

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
