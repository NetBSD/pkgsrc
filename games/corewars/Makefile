# $NetBSD: Makefile,v 1.5 2003/05/02 11:54:53 wiz Exp $
#

DISTNAME=	corewars-0.9.11
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=corewars/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://corewars.sourceforge.net/
COMMENT=	programs on a virtual machine, fighting each other

DEPENDS+=	gtk+>=1.2.10nb4:../../x11/gtk

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
USE_GMAKE=	YES

.include "../../mk/bsd.pkg.mk"
