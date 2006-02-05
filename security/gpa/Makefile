# $NetBSD: Makefile,v 1.20 2006/02/05 23:10:43 joerg Exp $
#

DISTNAME=	gpa-0.7.0
PKGREVISION=	5
CATEGORIES=	x11 security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/alpha/gpa/

MAINTAINER=	pr@alles.prima.de
HOMEPAGE=	http://www.gnupg.org/gpa.html
COMMENT=	GUI frontend to gnupg

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

LIBS+=			${BUILDLINK_LDADD.getopt}

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
