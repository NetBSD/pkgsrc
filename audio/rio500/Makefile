# $NetBSD: Makefile,v 1.25 2016/07/10 09:44:56 rillig Exp $
#

DISTNAME=	rio500-0.7
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rio500/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rio500.sourceforge.net/
COMMENT=	Utilities to manage your Diamond Rio 500 MP3 player
LICENSE=	gnu-gpl-v2

NOT_FOR_PLATFORM=	Interix-*-*

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-devicepath=/dev
CONFIGURE_ARGS+=	--with-deviceentry=urio0

REPLACE_SH=		scripts/rio_add_directory

.include "../../devel/glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
