# $NetBSD: Makefile,v 1.5 2003/03/29 12:42:12 jmmv Exp $
#

DISTNAME=	pkgsurvey-0.0
WRKSRC=		${WRKDIR}
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	agc@pkgsrc.org
COMMENT=	utility to collate pkg information, and mail to central census site

NO_CHECKSUM=    yes
NO_CONFIGURE=   yes
NO_BUILD=	yes

do-install:
	${SED} -e 's|\$${PKG_INFO}|${PKG_INFO}|'			\
		-e 's|\$${UNAME}|${UNAME}|g'				\
		${FILESDIR}/pkgsurvey.sh > ${PREFIX}/bin/pkgsurvey
	${CHMOD} 755 ${PREFIX}/bin/pkgsurvey

.include "../../mk/bsd.pkg.mk"
