# $NetBSD: Makefile,v 1.44 2003/05/02 11:54:35 wiz Exp $
#

DISTNAME=		libglade-0.17
PKGREVISION=		3
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libglade/0.17/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.daa.com.au/~james/gnome/
COMMENT=		Runtime interpreter for GLADE gui files

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
.  include "../../databases/db/buildlink2.mk"
CPPFLAGS+=		-I${BUILDLINK_PREFIX.db}/include/db2
.endif

MAKE_ENV+=	DISPLAY=${DISPLAY}

pre-configure:
	${RM} ${WRKSRC}/libgladeConf.sh

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../audio/esound/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
