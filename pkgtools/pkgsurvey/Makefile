# $NetBSD: Makefile,v 1.2 2001/02/01 12:58:33 agc Exp $
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

do-install:
	${SED} -e 's|\$${PKG_INFO}|${PKG_INFO}|'			\
		-e 's|\$${UNAME}|${UNAME}|g'				\
		${FILESDIR}/pkgsurvey.sh > ${PREFIX}/bin/pkgsurvey
	${CHMOD} 755 ${PREFIX}/bin/pkgsurvey

.include "../../mk/bsd.pkg.mk"
