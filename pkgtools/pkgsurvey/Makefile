# $NetBSD: Makefile,v 1.3 2001/02/17 17:51:31 wiz Exp $
#

DISTNAME=	pkgsurvey-0.0
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	agc@pkgsrc.org
COMMENT=	utility to collate pkg information, and mail to central census site

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
