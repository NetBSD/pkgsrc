# $NetBSD: Makefile,v 1.18 2020/03/31 22:44:54 gutteridge Exp $
#

DISTNAME=	libfm-1.3.1
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pcmanfm/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	http://pcmanfm.sourceforge.net/
COMMENT=	File management library
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		intltool msgfmt pkg-config

# needed for correct getgrgid_r() prototype
CPPFLAGS.SunOS+=	-D_POSIX_PTHREAD_SEMANTICS

CONFIGURE_ARGS+=	--with-gtk=2

PKG_SYSCONFSUBDIR=	xdg
OWN_DIRS=		${PKG_SYSCONFDIR}/libfm
CONF_FILES+=		share/examples/libfm/libfm.conf \
			${PKG_SYSCONFDIR}/libfm/libfm.conf

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing paths.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	src/base/fm-file-info.c
SUBST_FILES.prefix+=	src/modules/vfs-menu.c
# Upstream has a typo in a hard-coded path of "xgd" where they mean "xdg".
# On the next update, check vfs-menu.c, as this may be corrected to "xdg".
SUBST_SED.prefix=	-e 's,/etc/xgd,${PKG_SYSCONFDIR},g'
SUBST_SED.prefix+=	-e 's,/usr/share,${PREFIX}/share,g'

# XXX: walk-around bug in build wrappers
#      they try to copy $PREFIX/include/libfm to work dir and there link libfm -> libfm-1.0 is resolved
#      in the end a consumer of libfm cannot find nonexisting include/libfm
post-install:
	${RUN} ${RM} -f ${DESTDIR}${PREFIX}/include/libfm
	${RUN} ${CP} -r ${DESTDIR}${PREFIX}/include/libfm-1.0 ${DESTDIR}${PREFIX}/include/libfm

.include "../../graphics/libexif/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/menu-cache/buildlink3.mk"
.include "../../sysutils/libfm-extra/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
