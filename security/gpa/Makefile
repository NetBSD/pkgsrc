# $NetBSD: Makefile,v 1.9 2003/07/13 13:53:10 wiz Exp $
#

DISTNAME=	gpa-0.4.3
PKGREVISION=	2
CATEGORIES=	x11 security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/alpha/gpa/

MAINTAINER=	pr@alles.prima.de
HOMEPAGE=	http://www.gnupg.org/gpa.html
COMMENT=	GUI frontend to gnupg

DEPENDS+=	gnupg>=1.0.6:../../security/gnupg

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_X11=	YES

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
