# $NetBSD: Makefile,v 1.1.1.1 2001/02/01 12:31:43 agc Exp $
#

DISTNAME=	pkgsurvey-0.0
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	agc@pkgsrc.org

WRKSRC=		${WRKDIR}
NO_CHECKSUM=    yes
NO_PATCH=       yes
NO_CONFIGURE=   yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:
	${SED} -e 's|\$${PKG_INFO}|${PKG_INFO}|'			\
		-e 's|\$${UNAME}|${UNAME}|g'				\
		${FILESDIR}/pkgsurvey.sh > ${PREFIX}/bin/pkgsurvey
	${CHMOD} 755 ${PREFIX}/bin/pkgsurvey

.include "../../mk/bsd.pkg.mk"
