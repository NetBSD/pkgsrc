# $NetBSD: Makefile,v 1.19 2004/02/06 19:04:25 jlam Exp $
#

DISTNAME=	gensolpkg-1.10
PKGREVISION=	1
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	veego@NetBSD.org
COMMENT=	Utility to generate a Solaris package

ONLY_FOR_PLATFORM=	SunOS-*-*	# uses Solaris pkgmk(1)

MAKE_ENV+=	CPPFLAGS="" CC=${CC:Q}
MAKEFLAGS+=	PREFIX=${PREFIX:Q} ZOULARISBASE=${ZOULARISBASE:Q}

do-install:
	cd ${WRKSRC} && ${MAKE} install PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
