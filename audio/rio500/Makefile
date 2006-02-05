# $NetBSD: Makefile,v 1.19 2006/02/05 23:08:13 joerg Exp $
#

DISTNAME=	rio500-0.7
PKGREVISION=	3
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
