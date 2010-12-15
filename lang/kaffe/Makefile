# $NetBSD: Makefile,v 1.75 2010/12/15 16:06:26 abs Exp $
#

.include "Makefile.common"

PKGREVISION=	6

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
	${INSTALL_DATA} ${WRKSRC}/license.terms ${DESTDIR}${JAVA_HOME}

.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
