# $NetBSD: Makefile,v 1.36.2.1 2002/08/22 11:10:42 jlam Exp $
#

DISTNAME=		libglade-0.17
PKGREVISION=		1
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/libglade/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.daa.com.au/~james/gnome/
COMMENT=		Runtime interpreter for GLADE gui files

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
.include "../../databases/db/buildlink.mk"
CPPFLAGS+=		-I${BUILDLINK_DIR}/include/db2
.endif

pre-configure:
	${RM} ${WRKSRC}/libgladeConf.sh

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../textproc/libxml/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"
.include "../../audio/esound/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
