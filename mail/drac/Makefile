# $NetBSD: Makefile,v 1.16 2007/02/22 19:26:41 wiz Exp $
#

DISTNAME=	drac
PKGNAME=	drac-1.12
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cc.umanitoba.ca/src/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	groo@NetBSD.org
HOMEPAGE=	http://mail.cc.umanitoba.ca/drac/
COMMENT=	Dynamic Relay Authorization Control

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME_NOREV}

MAKE_ENV+=	MKDIR=${MKDIR:Q}
MAKE_ENV+=	INSTALL=${INSTALL:Q}
MAKE_ENV+=	RANLIB=${RANLIB:Q}
MAKE_ENV+=	EBIN="${LOCALBASE}/libexec"
MAKE_ENV+=	MAN="${LOCALBASE}/man/man"
MAKE_ENV+=	EXAMPLES="${LOCALBASE}/share/examples/drac"

.include "../../mk/bsd.pkg.mk"
