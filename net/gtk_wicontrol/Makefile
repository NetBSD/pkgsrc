# $NetBSD: Makefile,v 1.3 2001/07/28 21:11:25 tron Exp $

DISTNAME=	gtk_wicontrol-0.16
CATEGORIES=	net
MASTER_SITES=	http://www.izawa.sh/software/gtk_wicontrol/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.izawa.sh/software/gtk_wicontrol/
COMMENT=	GTK+-based Wavelan status meter

DEPENDS+=	gtk+-1.2.*:../../x11/gtk

ONLY_FOR_PLATFORM=	*BSD-*-*

USE_X11=	yes
GNU_CONFIGURE=	YES
USE_GMAKE=	yes
USE_LIBINTL=	yes

.include "../../mk/bsd.pkg.mk"
