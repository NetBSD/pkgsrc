# $NetBSD: Makefile,v 1.2 2000/05/16 16:02:04 hubertf Exp $
#

DISTNAME=	pkg_tarup-1.0.1
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
