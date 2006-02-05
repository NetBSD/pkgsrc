# $NetBSD: Makefile,v 1.12 2006/02/05 23:09:24 joerg Exp $
#

DISTNAME=	xgospel-1.12d
PKGREVISION=	2
CATEGORIES=	games x11
MASTER_SITES=	http://img.teaser.fr/~jlgailly//

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gailly.net/xgospel/
COMMENT=	X11 based IGS client for online "go" playing

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

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
