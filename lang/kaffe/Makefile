# $NetBSD: Makefile,v 1.71 2007/12/27 16:05:11 joerg Exp $
#

.include "Makefile.common"

PKGREVISION=	3

CONFLICTS+=		kaffe-nox11-[0-9]*

USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--disable-native-awt
CONFIGURE_ARGS+=	--disable-gtk-peer
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--without-esd
CONFIGURE_ARGS+=	--disable-esdtest
MAKE_ENV+=		PKGLOCALEDIR=${PREFIX}/${PKGLOCALEDIR}

JAVA_WRAPPERS=		appletviewer jar java javac javadoc javah javakey \
			javap jdb rmic rmiregistry serialver

.include "../../mk/bsd.prefs.mk"

UNLIMIT_RESOURCES=        datasize
LIBS+= -lltdl

.include "../../devel/gettext-lib/buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/license.terms ${JAVA_HOME}

.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
