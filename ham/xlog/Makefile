# $NetBSD: Makefile,v 1.4 2004/01/24 13:40:44 grant Exp $
#

DISTNAME=	xlog-0.8
PKGREVISION=	1
CATEGORIES=	ham
MASTER_SITES=	http://people.debian.org/~pa3aba/download/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://people.debian.org/~pa3aba/xlog.html
COMMENT=	Amateur Radio logging program

USE_BUILDLINK2=	yes
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--enable-hamlib

.include "../../ham/hamlib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
