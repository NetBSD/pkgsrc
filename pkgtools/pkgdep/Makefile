# $NetBSD: Makefile,v 1.4 2001/12/15 20:25:39 agc Exp $
#

DISTNAME=	pkgdep-1.0
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	sakamoto@netbsd.org
COMMENT=	Script for displaying dependence information on software packages

USE_PERL5=	YES

EXTRACT_ONLY=	# empty
WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes

do-build:
	${CP} ${FILESDIR}/pkgdep.pl ${WRKDIR}/pkgdep
#	${SED} -e 's|/usr/pkgsrc|${_PKGSRCDIR}|' \
#		${FILESDIR}/pkgdep.pl > ${WRKDIR}/pkgdep

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/pkgdep ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
