# $NetBSD: Makefile,v 1.3 2000/11/11 17:49:23 tron Exp $
#

DISTNAME=	rio500-0.7
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rio500/}

MAINTAINER=	ad@netbsd.org
HOMEPAGE=	http://rio500.sourceforge.net/

DEPENDS+=	glib>=1.2.0:../../devel/glib

USE_GMAKE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-devicepath=/dev --with-deviceentry=urio0

.include "../../mk/bsd.pkg.mk"
