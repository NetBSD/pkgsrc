# $NetBSD: Makefile,v 1.15 2005/04/11 21:44:56 tv Exp $
#

DISTNAME=	rio500-0.7
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rio500/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://rio500.sourceforge.net/
COMMENT=	Utilities to manage your Diamond Rio 500 MP3 player

USE_GNU_TOOLS+=	make

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-devicepath=/dev --with-deviceentry=urio0

.include "../../devel/glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
