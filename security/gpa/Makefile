# $NetBSD: Makefile,v 1.1.1.1 2001/06/28 17:01:03 wiz Exp $
#

DISTNAME=	gpa-0.4.1
CATEGORIES=	x11 security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/alpha/gpa/

MAINTAINER=	pr@alles.prima.de
HOMEPAGE=	http://www.gnupg.org/gpa.html
COMMENT=	GUI frontend to gnupg

DEPENDS+=	gnupg>=1.0.0:../../security/gnupg

GNU_CONFIGURE=		YES
USE_CONFIG_WRAPPER=	YES
USE_BUILDLINK_ONLY=	YES

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
