# $NetBSD: Makefile,v 1.41 2002/10/05 04:10:03 rh Exp $
#

DISTNAME=		libglade-0.17
PKGREVISION=		2
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/libglade/}

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

DISPLAY?=	# empty if unset
checkforx:
.if ${DISPLAY}=="" || ${DISPLAY_OK:!${X11BASE}/bin/xdpyinfo >/dev/null 2>&1 && echo YES || echo NO!} == "NO"
.if exists(${X11BASE}/bin/Xvfb)
	-${SETENV} XAUTHORITY= ${X11BASE}/bin/Xvfb :2 &
DISPLAY=	':2'
.else
	@${ECHO} "Error: Environment variable DISPLAY must be set"
	@${ECHO} "       and point to a connectible X server."
	@${FALSE}
.endif	# Xvfb
.endif	# DISPLAY

MAKE_ENV+=	DISPLAY=${DISPLAY}

pre-configure:
	${RM} ${WRKSRC}/libgladeConf.sh

pre-build: checkforx

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../audio/esound/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
