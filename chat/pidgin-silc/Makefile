# $NetBSD: Makefile,v 1.11 2009/09/06 21:06:45 abs Exp $
#

PKGNAME=		pidgin-silc-${PIDGIN_VERSION}
COMMENT=		SILC plugin for the Pidgin instant messenger

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../chat/libpurple/Makefile.common"

USE_TOOLS+=		msgfmt perl intltool

BUILD_DIRS=		libpurple/protocols/silc

# Because pkgsrc's silc-toolkit is too old, we have to jump through some very,
# very, VERY nasty hoops to build this package. Hopefully this hack can be
# removed soon.

BUNDLE_SILC=yes
.if defined(BUNDLE_SILC)

DISTINFO_FILE=		${.CURDIR}/../../chat/pidgin-silc/distinfo
SITES.silc-toolkit-1.1.7.tar.gz= \
			http://www.silcnet.org/download/toolkit/sources/
DISTFILES+=		pidgin-${PIDGIN_VERSION}.tar.bz2 silc-toolkit-1.1.7.tar.gz
CFLAGS+=		-fPIC
pre-configure:
	# Build libsilc statically and install it into the buildlink dir
	cd ${WRKDIR}/silc-toolkit-1.1.7 && ${SETENV} ${CONFIGURE_ENV} \
	./configure --disable-asm --enable-static --disable-shared \
	--without-libtoolfix --prefix=${BUILDLINK_DIR} && \
	${SETENV} ${MAKE_ENV} gmake && \
	${SETENV} ${MAKE_ENV} gmake install && \
	cp ${WRKDIR}/silc-toolkit-1.1.7/lib/.libs/*.a \
	${WRKSRC}/libpurple/protocols/silc

SUBST_CLASSES+=		linkage
SUBST_STAGE.linkage=	post-configure
SUBST_MESSAGE.linkage=	Fixing static linkage
SUBST_FILES.linkage=	libpurple/protocols/silc/Makefile
SUBST_SED.linkage=	-e 's/-lsilcclient -lsilc/-Wl,--whole-archive,libsilcclient.a,libsilc.a,--no-whole-archive/'

.endif

BUILDLINK_API_DEPENDS.libpurple+=	libpurple-${PIDGIN_VERSION}{,nb*}
.include "../../chat/libpurple/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
#.include "../../devel/silc-toolkit/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
