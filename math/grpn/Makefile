# $NetBSD: Makefile,v 1.14 2004/10/03 00:12:56 tv Exp $
#

DISTNAME=	grpn-1.1.2
PKGREVISION=	4
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
