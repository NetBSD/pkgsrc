# $NetBSD: Makefile,v 1.12 2004/04/25 01:05:18 wiz Exp $
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
USE_BUILDLINK3=	YES
NO_EXPORT_CPP=	YES

MAKE_ENV+=	MKDIR="${MKDIR}"
MAKE_ENV+=	INSTALL="${INSTALL}"
MAKE_ENV+=	RANLIB="${RANLIB}"
MAKE_ENV+=	EBIN="${LOCALBASE}/libexec"
MAKE_ENV+=	MAN="${LOCALBASE}/man/man"
MAKE_ENV+=	EXAMPLES="${LOCALBASE}/share/examples/drac"

.include "../../mk/bsd.pkg.mk"
