# $NetBSD: Makefile,v 1.13 2004/04/24 04:22:39 snj Exp $
#

DISTNAME=	grpn-1.1.2
PKGREVISION=	3
CATEGORIES=	math
MASTER_SITES=	ftp://lashwhip.com/pub/ \
		http://lashwhip.com/grpn/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://lashwhip.com/grpn.html
COMMENT=	Graphical reverse polish notation (RPN) calculator

USE_BUILDLINK3=	yes
USE_X11=	# defined
ALL_TARGET=	grpn

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
