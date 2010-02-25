# $NetBSD: Makefile,v 1.18 2010/02/25 15:08:02 joerg Exp $
#

DISTNAME=	drac
PKGNAME=	drac-1.12
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cc.umanitoba.ca/src/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
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
