# $NetBSD: Makefile,v 1.2 2003/05/02 11:54:44 wiz Exp $
#

DISTNAME=	gbib-0.1.1b
PKGREVISION=	1
CATEGORIES=	editors gnome
MASTER_SITES=	ftp://ftp.seul.org/pub/gbib/src/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://gbib.seul.org/
COMMENT=	user-friendly editor and browser for BibTeX databases

USE_X11=	YES
USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
