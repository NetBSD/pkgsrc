# $NetBSD: Makefile,v 1.11 2003/07/13 13:52:31 wiz Exp $
#

DISTNAME=	grpn-1.1.2
PKGREVISION=	3
CATEGORIES=	math
MASTER_SITES=	ftp://lashwhip.com/pub/ \
		http://lashwhip.com/grpn/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://lashwhip.com/grpn.html
COMMENT=	Graphical reverse polish notation (RPN) calculator

USE_BUILDLINK2=	# defined
USE_X11=	# defined
ALL_TARGET=	grpn

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
