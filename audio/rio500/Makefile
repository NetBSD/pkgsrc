# $NetBSD: Makefile,v 1.8 2003/05/02 11:53:44 wiz Exp $
#

DISTNAME=	rio500-0.7
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rio500/}

MAINTAINER=	ad@netbsd.org
HOMEPAGE=	http://rio500.sourceforge.net/
COMMENT=	Utilities to manage your Diamond Rio 500 MP3 player

DEPENDS+=	glib>=1.2.0:../../devel/glib

USE_GMAKE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-devicepath=/dev --with-deviceentry=urio0

.include "../../mk/bsd.pkg.mk"
