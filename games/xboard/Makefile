# $NetBSD: Makefile,v 1.30 2005/09/28 20:52:22 rillig Exp $

DISTNAME=	xboard-4.2.6
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU:=xboard/}

MAINTAINER=	simonb@NetBSD.org
HOMEPAGE=	http://www.tim-mann.org/xboard.html
COMMENT=	Graphical frontend for chess engines and servers

CONFIGURE_ARGS+=	--enable-xpm
CONFIGURE_ARGS+=	--enable-zippy	# interface to ICS
CONFIGURE_ENV+=		PERLPATH="${PERL5}"
GNU_CONFIGURE=		yes
USE_TOOLS+=		perl:run

INFO_FILES=	xboard.info

.include "../../mk/bsd.prefs.mk"

.if defined(XAW_TYPE) && (${XAW_TYPE} == "3d" || ${XAW_TYPE} == "xpm")
CONFIGURE_ARGS+=	--with-Xaw3d
.endif

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
