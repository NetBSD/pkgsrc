# $NetBSD: Makefile,v 1.14 2001/05/22 08:36:21 agc Exp $
#

DISTNAME=	gensolpkg-1.10
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	veego@netbsd.org
COMMENT=	Utility to generate a Solaris package

ONLY_FOR_PLATFORM=	SunOS-*-*	# uses Solaris pkgmk(1)

MAKE_ENV+=	CPPFLAGS="" CC="${CC}"

do-install:
	cd ${WRKSRC} && ${MAKE} install PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
