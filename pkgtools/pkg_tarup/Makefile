# $NetBSD: Makefile,v 1.3 2001/02/17 17:51:27 wiz Exp $
#

DISTNAME=	pkg_tarup-1.0.1
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	hubertf@netbsd.org
COMMENT=	Generates binary package from installed pkg

WRKSRC=		${WRKDIR}
NO_CHECKSUM=    yes
NO_PATCH=       yes
NO_CONFIGURE=   yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/pkg_tarup ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
