# $NetBSD: Makefile,v 1.6 2002/01/18 09:23:58 martin Exp $
#

DISTNAME=	gpa-0.4.3
CATEGORIES=	x11 security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/alpha/gpa/

MAINTAINER=	pr@alles.prima.de
HOMEPAGE=	http://www.gnupg.org/gpa.html
COMMENT=	GUI frontend to gnupg

DEPENDS+=	gnupg>=1.0.6:../../security/gnupg

GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
