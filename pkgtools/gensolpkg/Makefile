# $NetBSD: Makefile,v 1.17 2003/01/31 12:18:31 abs Exp $
#

DISTNAME=	gensolpkg-1.10
PKGREVISION=	1
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	veego@netbsd.org
COMMENT=	Utility to generate a Solaris package

ONLY_FOR_PLATFORM=	SunOS-*-*	# uses Solaris pkgmk(1)

MAKE_ENV+=	CPPFLAGS="" CC=${CC:Q}
MAKEFLAGS+=	PREFIX=${PREFIX} ZOULARISBASE=${ZOULARISBASE}

do-install:
	cd ${WRKSRC} && ${MAKE} install PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
