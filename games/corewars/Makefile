# $NetBSD: Makefile,v 1.8 2003/07/13 13:51:42 wiz Exp $
#

DISTNAME=	corewars-0.9.11
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=corewars/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://corewars.sourceforge.net/
COMMENT=	programs on a virtual machine, fighting each other

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
