# $NetBSD: Makefile,v 1.1.1.1 2000/02/14 02:07:08 hubertf Exp $
#

DISTNAME=	pkg_tarup-1.0
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	hubertf@netbsd.org

WRKSRC=		${WRKDIR}
NO_CHECKSUM=    yes
NO_PATCH=       yes
NO_CONFIGURE=   yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/pkg_tarup ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
