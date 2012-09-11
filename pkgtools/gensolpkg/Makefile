# $NetBSD: Makefile,v 1.22 2012/09/11 23:19:35 asau Exp $
#

DISTNAME=	gensolpkg-1.10
PKGREVISION=	2
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	agc@NetBSD.org
COMMENT=	Utility to generate a Solaris package
LICENSE=	original-bsd

USE_BSD_MAKEFILE=	yes

ONLY_FOR_PLATFORM=	SunOS-*-*	# uses Solaris pkgmk(1)

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man1

MAKE_ENV+=	CPPFLAGS="" CC=${CC:Q}
MAKEFLAGS+=	PREFIX=${PREFIX}
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
