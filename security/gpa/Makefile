# $NetBSD: Makefile,v 1.6.2.1 2002/07/01 17:45:09 jlam Exp $
#

DISTNAME=	gpa-0.4.3
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
