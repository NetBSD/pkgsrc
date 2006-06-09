# $NetBSD: Makefile,v 1.19 2006/06/09 06:34:57 joerg Exp $
#

DISTNAME=	grpn-1.1.2
PKGREVISION=	5
CATEGORIES=	math
MASTER_SITES=	ftp://lashwhip.com/pub/ \
		http://lashwhip.com/grpn/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://lashwhip.com/grpn.html
COMMENT=	Graphical reverse polish notation (RPN) calculator

BUILD_TARGET=	grpn
USE_TOOLS+=	mkdirhier

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
