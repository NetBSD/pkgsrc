# $NetBSD: Makefile,v 1.5.4.1 2002/07/22 17:16:03 agc Exp $

DISTNAME=	pkg_tarup-1.0.3
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
	${INSTALL_PROGRAM_DIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/pkg_tarup ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
