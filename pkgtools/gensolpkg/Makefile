# $NetBSD: Makefile,v 1.12 2001/02/17 17:51:25 wiz Exp $
#

DISTNAME=	gensolpkg-1.9
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	veego@netbsd.org
COMMENT=	Utility to generate a Solaris package

ONLY_FOR_PLATFORM=	SunOS-*-*	# uses Solaris pkgmk(1)

MAKE_ENV+=	CPPFLAGS="" CC=${CC}

do-install:
	cd ${WRKSRC} && ${MAKE} install PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
