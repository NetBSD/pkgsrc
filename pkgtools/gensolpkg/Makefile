# $NetBSD: Makefile,v 1.8 2000/01/04 12:06:58 agc Exp $
#

DISTNAME=	gensolpkg-1.6
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	agc@netbsd.org
HOMEPAGE=	http://www.westley.demon.co.uk/software.html

ONLY_FOR_PLATFORM=	SunOS-*-*	# uses Solaris pkgmk(1)

MAKE_ENV+=	CPPFLAGS="" CC=${CC}

do-install:
	cd ${WRKSRC} && ${MAKE} install PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
