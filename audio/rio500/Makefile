# $NetBSD: Makefile,v 1.9 2003/05/02 13:02:19 wiz Exp $
#

DISTNAME=	rio500-0.7
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rio500/}

MAINTAINER=	ad@netbsd.org
HOMEPAGE=	http://rio500.sourceforge.net/
COMMENT=	Utilities to manage your Diamond Rio 500 MP3 player

USE_BUILDLINK2=	yes
USE_GMAKE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-devicepath=/dev --with-deviceentry=urio0

.include "../../devel/glib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
