# $NetBSD: Makefile,v 1.11 2004/01/22 07:15:00 grant Exp $
#

DISTNAME=	rio500-0.7
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rio500/}

MAINTAINER=	ad@NetBSD.org
HOMEPAGE=	http://rio500.sourceforge.net/
COMMENT=	Utilities to manage your Diamond Rio 500 MP3 player

USE_BUILDLINK2=	yes
USE_GNU_TOOLS+=	make

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-devicepath=/dev --with-deviceentry=urio0

.include "../../devel/glib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
