# $NetBSD: Makefile,v 1.21 2003/08/08 16:38:41 seb Exp $

DISTNAME=	xboard-4.2.6
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU:=xboard/}

MAINTAINER=	simonb@NetBSD.ORG
HOMEPAGE=	http://www.tim-mann.org/xboard.html
COMMENT=	Graphical frontend for chess engines and servers

USE_BUILDLINK2=		# defined
USE_X11=		# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--enable-xpm
CONFIGURE_ARGS+=	--enable-zippy	# interface to ICS

USE_NEW_TEXINFO=	YES
INFO_FILES=	xboard.info

.include "../../mk/bsd.prefs.mk"

.if defined(XAW_TYPE) && (${XAW_TYPE} == "3d" || ${XAW_TYPE} == "xpm")
CONFIGURE_ARGS+=	--with-Xaw3d
.endif

.include "../../lang/perl5/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/xaw.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
