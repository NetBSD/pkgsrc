# $NetBSD: Makefile,v 1.8 2003/05/02 11:56:17 wiz Exp $
#

DISTNAME=	gpa-0.4.3
PKGREVISION=	1
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
