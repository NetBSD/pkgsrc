# $NetBSD: Makefile,v 1.17 2007/03/24 19:21:26 joerg Exp $
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

INSTALLATION_DIRS=	include lib libexec ${PKGMANDIR}/man3 ${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
