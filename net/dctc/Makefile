# $NetBSD: Makefile,v 1.39 2009/04/30 20:59:15 zafer Exp $
#

DISTNAME=	dctc-0.85.4
PKGREVISION=	6
CATEGORIES=	net
MASTER_SITES=	http://ac2i.homelinux.com/dctc/ 

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ac2i.homelinux.com/dctc/
COMMENT=	Direct Connect clone (Direct Connect Text Client)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-manual-db-detect
USE_TOOLS+=		gmake perl:run pkg-config
USE_LIBTOOL=		YES

CPPFLAGS+=	-I${BUILDLINK_PREFIX.db4}/include/db4

SUBST_CLASSES+=		inethack
SUBST_FILES.inethack=	src/dc_manage.c src/dc_manage_master.c
SUBST_FILES.inethack+=	src/main.c src/main_master.c src/var.h
SUBST_SED.inethack+=	-e 's,\(G_.*LOCK.*(\)inet_ntoa,\1my_inet_ntoa,g'
SUBST_STAGE.inethack=	post-patch

post-configure:
	@${TOUCH} ${WRKSRC:Q}/stamp-h.in ${WRKSRC:Q}/config.h.in
	@${TOUCH} ${WRKSRC:Q}/config.status ${WRKSRC:Q}/stamp-h
	@${ECHO} '#ifndef MSG_NOSIGNAL' >> ${WRKSRC:Q}/config.h
	@${ECHO} '# define MSG_NOSIGNAL 0' >> ${WRKSRC:Q}/config.h
	@${ECHO} '#endif' >> ${WRKSRC:Q}/config.h

.include "../../databases/db4/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
