# $NetBSD: Makefile,v 1.7.2.1 2002/06/23 18:52:37 jlam Exp $
#

DISTNAME=	grpn-1.1.2
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	ftp://lashwhip.com/pub/ \
		http://lashwhip.com/grpn/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://lashwhip.com/grpn.html
COMMENT=	Graphical reverse polish notation (RPN) calculator

USE_BUILDLINK_ONLY=     yes
ALL_TARGET=	grpn

#DEPENDS+=	gtk+-1.2.*:../../x11/gtk
#USE_X11=	yes

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
