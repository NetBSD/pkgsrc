# $NetBSD: Makefile,v 1.3 2001/12/10 17:56:24 martti Exp $
#

DISTNAME=	gpa-0.4.2
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
