# $NetBSD: Makefile,v 1.15 2001/11/29 13:27:46 jlam Exp $

DISTNAME=		xboard-4.2.3
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_GNU:=xboard/}

MAINTAINER=		simonb@NetBSD.ORG
HOMEPAGE=		http://www.tim-mann.org/xboard.html
COMMENT=		graphical frontend for chess engines and servers

INFO_FILES=		xboard.info

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-xpm
CONFIGURE_ARGS+=	--enable-zippy	# interface to ICS

.include "../../mk/bsd.prefs.mk"

.if defined(XAW_TYPE) && (${XAW_TYPE} == "3d" || ${XAW_TYPE} == "xpm")
CONFIGURE_ARGS+=	--with-Xaw3d
.endif

.include "../../lang/perl5/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/xaw.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
