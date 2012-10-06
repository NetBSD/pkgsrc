# $NetBSD: Makefile,v 1.19 2012/10/06 11:55:01 asau Exp $
#

DISTNAME=	xgospel-1.12d
PKGREVISION=	3
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
.  endif
.endif

# Don't find libintl.a...it's only needed on SCO UNIX.
CONFIGURE_ENV+=		ac_cv_lib_intl=no

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
