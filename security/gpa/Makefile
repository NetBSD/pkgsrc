# $NetBSD: Makefile,v 1.10 2003/12/14 15:12:11 wiz Exp $
#

DISTNAME=	gpa-0.7.0
CATEGORIES=	x11 security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/alpha/gpa/

MAINTAINER=	pr@alles.prima.de
HOMEPAGE=	http://www.gnupg.org/gpa.html
COMMENT=	GUI frontend to gnupg

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES

.include "../../security/gpgme/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
