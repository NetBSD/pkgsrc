# $NetBSD: Makefile,v 1.20 2009/08/26 19:57:14 sno Exp $
#

DISTNAME=	transcalc-0.14
PKGREVISION=	4
CATEGORIES=	cad
MASTER_SITES=	http://transcalc.sourceforge.net/
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=transcalc/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://transcalc.sourceforge.net/
COMMENT=	Transmission line analysis/synthesis

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake pkg-config

.include "../../x11/gtk2/buildlink3.mk"
#.include "../../graphics/imlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
