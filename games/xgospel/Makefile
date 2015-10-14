# $NetBSD: Makefile,v 1.20 2015/10/14 20:17:26 wiz Exp $

DISTNAME=	xgospel-1.12d
PKGREVISION=	4
CATEGORIES=	games x11
MASTER_SITES=	http://gailly.net/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gailly.net/go.html
COMMENT=	X11 based IGS client for online "go" playing

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		yes
XAW_TYPE=		3d

.include "../../mk/bsd.prefs.mk"

.if defined(XAW_TYPE)
.  if (${XAW_TYPE} == "3d") || (${XAW_TYPE} == "xpm")
CONFIGURE_ARGS+=	--with-xaw3d
# does not directly support Xaw3d
.PHONY: buildlink-Xaw3d-inc-hack
pre-configure: buildlink-Xaw3d-inc-hack

buildlink-Xaw3d-inc-hack: buildlink-directories
	cd ${BUILDLINK_DIR}/include/X11 && ln -s Xaw3d Xaw
.  endif
.endif

# Don't find libintl.a...it's only needed on SCO UNIX.
CONFIGURE_ENV+=		ac_cv_lib_intl=no

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
