# $NetBSD: Makefile,v 1.1.1.1 2003/07/03 00:45:22 wulf Exp $
#

DISTNAME=	xlog-0.8
CATEGORIES=	ham
MASTER_SITES=	http://people.debian.org/~pa3aba/download/

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://people.debian.org/~pa3aba/xlog.html
COMMENT=	Amateur Radio logging program

USE_BUILDLINK2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--enable-hamlib

.include "../../ham/hamlib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
