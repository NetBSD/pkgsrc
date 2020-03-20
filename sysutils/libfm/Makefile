# $NetBSD: Makefile,v 1.17 2020/03/20 11:58:21 nia Exp $
#

DISTNAME=	libfm-1.3.1
PKGREVISION=	3
CATEGORIES=	devel
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

# XXX: walk-around bug in build wrappers
#      they try to copy $PREFIX/include/libfm to work dir and there link libfm -> libfm-1.0 is resolved
#      in the end a consumer of libfm cannot find nonexisting include/libfm
post-install:
	${RUN} rm -f ${DESTDIR}${PREFIX}/include/libfm
	${RUN} cp -r ${DESTDIR}${PREFIX}/include/libfm-1.0 ${DESTDIR}${PREFIX}/include/libfm

.include "../../graphics/libexif/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/menu-cache/buildlink3.mk"
.include "../../sysutils/libfm-extra/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
