# $NetBSD: Makefile,v 1.4 2003/03/28 21:14:28 wiz Exp $
#

DISTNAME=	pkgsurvey-0.0
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	agc@pkgsrc.org
COMMENT=	utility to collate pkg information, and mail to central census site

WRKSRC=		${WRKDIR}
NO_CHECKSUM=    yes
NO_CONFIGURE=   yes
NO_BUILD=	yes

do-install:
	${SED} -e 's|\$${PKG_INFO}|${PKG_INFO}|'			\
		-e 's|\$${UNAME}|${UNAME}|g'				\
		${FILESDIR}/pkgsurvey.sh > ${PREFIX}/bin/pkgsurvey
	${CHMOD} 755 ${PREFIX}/bin/pkgsurvey

.include "../../mk/bsd.pkg.mk"
