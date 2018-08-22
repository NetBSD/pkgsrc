# $NetBSD: Makefile,v 1.58 2018/08/22 09:45:51 wiz Exp $

DISTNAME=	dctc-0.85.9
PKGREVISION=	14
CATEGORIES=	net
#MASTER_SITES=	http://ac2i.homelinux.com/dctc/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://ac2i.homelinux.com/dctc/
COMMENT=	Direct Connect clone (Direct Connect Text Client)
LICENSE=	gnu-gpl-v2

BDB_ACCEPTED=		db4 db5
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl:run pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-manual-db-detect
CONFIGURE_ENV+=		BDB_TYPE=${BDB_TYPE}

REPLACE_PERL+=		GDLjoiner

CPPFLAGS+=		-I${BDBBASE}/include/${BDB_TYPE}
BUILDLINK_TRANSFORM+=	l:db4:${BDB_TYPE}

SUBST_CLASSES+=		inethack
SUBST_STAGE.inethack=	pre-configure
SUBST_FILES.inethack=	src/dc_manage.c src/dc_manage_master.c
SUBST_FILES.inethack+=	src/main.c src/main_master.c src/var.h
SUBST_SED.inethack+=	-e 's,\(G_.*LOCK.*(\)inet_ntoa,\1my_inet_ntoa,g'

post-configure:
	${TOUCH} ${WRKSRC}/stamp-h.in ${WRKSRC}/config.h.in
	${TOUCH} ${WRKSRC}/config.status ${WRKSRC}/stamp-h
	${ECHO} '#ifndef MSG_NOSIGNAL' >> ${WRKSRC}/config.h
	${ECHO} '# define MSG_NOSIGNAL 0' >> ${WRKSRC}/config.h
	${ECHO} '#endif' >> ${WRKSRC}/config.h

.include "../../devel/glib2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
