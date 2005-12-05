# $NetBSD: Makefile,v 1.18 2005/12/05 20:49:49 rillig Exp $
#

DISTNAME=	rio500-0.7
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rio500/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://rio500.sourceforge.net/
COMMENT=	Utilities to manage your Diamond Rio 500 MP3 player

NOT_FOR_PLATFORM=	Interix-*-*

USE_TOOLS+=	gmake

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-devicepath=/dev
CONFIGURE_ARGS+=	--with-deviceentry=urio0

.include "../../devel/glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
