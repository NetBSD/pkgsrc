# $NetBSD: Makefile,v 1.3 2003/06/02 01:20:10 jschauma Exp $
#

DISTNAME=	gbib-0.1.1b
PKGREVISION=	1
CATEGORIES=	editors gnome
MASTER_SITES=	ftp://ftp.seul.org/pub/gbib/src/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://gbib.seul.org/
COMMENT=	user-friendly editor and browser for BibTeX databases

USE_X11=	YES
USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
