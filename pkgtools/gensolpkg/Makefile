# $NetBSD: Makefile,v 1.11 2001/01/21 23:43:13 veego Exp $
#

DISTNAME=	gensolpkg-1.9
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	veego@netbsd.org

ONLY_FOR_PLATFORM=	SunOS-*-*	# uses Solaris pkgmk(1)

MAKE_ENV+=	CPPFLAGS="" CC=${CC}

do-install:
	cd ${WRKSRC} && ${MAKE} install PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
