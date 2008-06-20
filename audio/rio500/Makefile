# $NetBSD: Makefile,v 1.21 2008/06/20 01:09:07 joerg Exp $
#

DISTNAME=	rio500-0.7
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rio500/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rio500.sourceforge.net/
COMMENT=	Utilities to manage your Diamond Rio 500 MP3 player

PKG_DESTDIR_SUPPORT=	user-destdir

NOT_FOR_PLATFORM=	Interix-*-*

USE_TOOLS+=	gmake

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-devicepath=/dev
CONFIGURE_ARGS+=	--with-deviceentry=urio0

.include "../../devel/glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
