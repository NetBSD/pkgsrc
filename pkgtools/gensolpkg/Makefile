# $NetBSD: Makefile,v 1.15 2002/01/11 17:38:45 seb Exp $
#

DISTNAME=	gensolpkg-1.10
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	veego@netbsd.org
COMMENT=	Utility to generate a Solaris package

ONLY_FOR_PLATFORM=	SunOS-*-*	# uses Solaris pkgmk(1)

MAKE_ENV+=	CPPFLAGS="" CC="${CC}"
MAKEFLAGS+=	PREFIX=${PREFIX}

do-install:
	cd ${WRKSRC} && ${MAKE} install PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
