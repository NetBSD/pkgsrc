# $NetBSD: Makefile,v 1.10 2004/01/20 12:19:43 agc Exp $
#

DISTNAME=	drac
PKGNAME=	drac-1.12
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cc.umanitoba.ca/src/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=	groo@NetBSD.org
HOMEPAGE=	http://mail.cc.umanitoba.ca/drac/
COMMENT=	Dynamic Relay Authorization Control

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME_NOREV}
USE_BUILDLINK2=	YES

MAKE_ENV+=	MKDIR="${MKDIR}"
MAKE_ENV+=	INSTALL="${INSTALL}"
MAKE_ENV+=	RANLIB="${RANLIB}"
MAKE_ENV+=	EBIN="${LOCALBASE}/libexec"
MAKE_ENV+=	MAN="${LOCALBASE}/man/man"
MAKE_ENV+=	EXAMPLES="${LOCALBASE}/share/examples/drac"

.include "../../mk/bsd.pkg.mk"
