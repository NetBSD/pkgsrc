# $NetBSD: Makefile,v 1.7 2003/03/09 12:25:53 jmmv Exp $
#

DISTNAME=	drac
PKGNAME=	drac-1.12
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cc.umanitoba.ca/src/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=	groo@netbsd.org
HOMEPAGE=	http://mail.cc.umanitoba.ca/drac/
COMMENT=	Dynamic Relay Authorization Control

DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}
USE_BUILDLINK2=	YES

MAKE_ENV+=	MKDIR="${MKDIR}"
MAKE_ENV+=	INSTALL="${INSTALL}"
MAKE_ENV+=	RANLIB="${RANLIB}"
MAKE_ENV+=	EBIN="${LOCALBASE}/libexec"
MAKE_ENV+=	MAN="${LOCALBASE}/man/man"
MAKE_ENV+=	EXAMPLES="${LOCALBASE}/share/examples/drac"

.include "../../mk/bsd.pkg.mk"
