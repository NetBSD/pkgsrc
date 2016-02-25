# $NetBSD: Makefile,v 1.19 2016/02/25 17:52:45 jperkin Exp $
#

DISTNAME=	mpdist-3.7.1
PKGNAME=	mp-3.7.1
PKGREVISION=	4
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mpdist/}

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://mpdist.sourceforge.net/
COMMENT=	PostScript pretty printer

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

CONFIGURE_ARGS.SunOS+=	# empty
CONFIGURE_ARGS.*+=	--enable-bsd-print

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
