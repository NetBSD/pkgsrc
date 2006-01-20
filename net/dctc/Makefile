# $NetBSD: Makefile,v 1.29 2006/01/20 22:44:50 joerg Exp $
#

DISTNAME=	dctc-0.85.4
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.ac2i.tzo.com/dctc/ \
		http://brainz.servebeer.com/dctc/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ac2i.tzo.com/dctc/
COMMENT=	Direct Connect clone (Direct Connect Text Client)

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-manual-db-detect
USE_TOOLS+=		gmake perl:run
USE_LIBTOOL=		YES

CPPFLAGS+=	-I${BUILDLINK_PREFIX.db4}/include/db4

SUBST_CLASSES+=		inethack
SUBST_FILES.inethack=	src/dc_manage.c src/dc_manage_master.c
SUBST_FILES.inethack+=	src/main.c src/main_master.c src/var.h
SUBST_SED.inethack+=	-e 's,\(G_.*LOCK.*(\)inet_ntoa,\1my_inet_ntoa,g'
SUBST_STAGE.inethack=	post-patch

post-configure:
	@${TOUCH} ${WRKSRC}/stamp-h.in ${WRKSRC}/config.h.in
	@${TOUCH} ${WRKSRC}/config.status ${WRKSRC}/stamp-h
	@${ECHO} '#ifndef MSG_NOSIGNAL' >> ${WRKSRC}/config.h
	@${ECHO} '# define MSG_NOSIGNAL 0' >> ${WRKSRC}/config.h
	@${ECHO} '#endif' >> ${WRKSRC}/config.h

.include "../../databases/db4/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
