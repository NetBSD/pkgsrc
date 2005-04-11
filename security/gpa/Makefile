# $NetBSD: Makefile,v 1.15 2005/04/11 21:47:11 tv Exp $
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

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
