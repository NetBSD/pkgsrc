# $NetBSD: Makefile,v 1.3 2002/02/08 00:12:38 jlam Exp $
#

DISTNAME=	xgospel-1.12d
CATEGORIES=	games x11
MASTER_SITES=	http://img.teaser.fr/~jlgailly//

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://gailly.net/xgospel/
COMMENT=	X11 based IGS client

USE_BUILDLINK_ONLY=	yes
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

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/xaw.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
