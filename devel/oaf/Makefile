# $NetBSD: Makefile,v 1.11 2001/10/01 11:01:02 rh Exp $
#

DISTNAME=		oaf-0.6.6
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/oaf/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		new object activation framework for GNOME

GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CPPFLAGS+=		-I${X11PREFIX}/include -I${LOCALBASE}/include

#
# use of orbit/buildlink.mk (pulled in via gnome-libs) causes the
# buildlink location for orbit-config to be entered in the configure
# scripts.  Fix by replacing @ORBIT_CONFIG@ before GNU configure has
# a chance to touch it.
#
pre-configure:
.for cfg in oafConf.sh.in oaf-config.in
	cd ${WRKSRC} &&							\
	${CP} ${cfg} ${cfg}.old &&			\
	${SED} < ${cfg}.old > ${cfg}			\
	    -e 's|@ORBIT_CONFIG@|${LOCALBASE}/bin/orbit-config|g'
.endfor

.include "../../textproc/libxml/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"
.include "../../devel/popt/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
