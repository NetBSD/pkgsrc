# $NetBSD: Makefile,v 1.7 2003/05/11 08:58:17 jmc Exp $
#

DISTNAME=	corewars-0.9.11
PKGREVISION=	1
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
