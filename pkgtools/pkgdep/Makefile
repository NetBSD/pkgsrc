# $NetBSD: Makefile,v 1.6 2003/03/29 12:42:11 jmmv Exp $
#

DISTNAME=	pkgdep-1.0
WRKSRC=		${WRKDIR}
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	sakamoto@netbsd.org
COMMENT=	Script for displaying dependence information on software packages

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
