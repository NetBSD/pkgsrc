# $NetBSD: Makefile,v 1.5 2002/01/18 07:21:30 martti Exp $
#

DISTNAME=	gpa-0.4.3
CATEGORIES=	x11 security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/alpha/gpa/

MAINTAINER=	pr@alles.prima.de
HOMEPAGE=	http://www.gnupg.org/gpa.html
COMMENT=	GUI frontend to gnupg

DEPENDS+=	gnupg>=1.0.6:../../security/gnupg

# This can't be compiled on alpha/powerpc because __va_list is defined
# as struct in include/ansi.h instead of "char *"
NOT_FOR_PLATFORM=	*-*-alpha *-*-*ppc

GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
