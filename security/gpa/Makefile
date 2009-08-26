# $NetBSD: Makefile,v 1.24 2009/08/26 19:58:15 sno Exp $
#

DISTNAME=	gpa-0.7.0
PKGREVISION=	7
CATEGORIES=	x11 security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/alpha/gpa/

MAINTAINER=	pr@alles.prima.de
HOMEPAGE=	http://www.gnupg.org/related_software/gpa/
COMMENT=	GUI frontend to gnupg

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

LIBS+=			${BUILDLINK_LDADD.getopt}

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
