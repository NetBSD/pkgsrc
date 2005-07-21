# $NetBSD: Makefile,v 1.16 2005/07/21 16:29:56 wiz Exp $
#

DISTNAME=	gpa-0.7.0
PKGREVISION=	3
CATEGORIES=	x11 security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/alpha/gpa/

MAINTAINER=	pr@alles.prima.de
HOMEPAGE=	http://www.gnupg.org/gpa.html
COMMENT=	GUI frontend to gnupg

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
