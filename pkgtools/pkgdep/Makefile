# $NetBSD: Makefile,v 1.8 2004/01/20 12:23:57 agc Exp $
#

DISTNAME=	pkgdep-1.0
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	sakamoto@NetBSD.org
COMMENT=	Script for displaying dependence information on software packages

WRKSRC=		${WRKDIR}
USE_PERL5=	YES

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

do-build:
	${CP} ${FILESDIR}/pkgdep.pl ${WRKDIR}/pkgdep
#	${SED} -e 's|/usr/pkgsrc|${_PKGSRCDIR}|' \
#		${FILESDIR}/pkgdep.pl > ${WRKDIR}/pkgdep

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/pkgdep ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
