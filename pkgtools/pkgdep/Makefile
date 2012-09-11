# $NetBSD: Makefile,v 1.16 2012/09/11 23:19:38 asau Exp $
#

DISTNAME=	pkgdep-1.0
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Script for displaying dependence information on software packages

WRKSRC=		${WRKDIR}/files
USE_TOOLS+=	perl:run

REPLACE_PERL=	pkgdep.pl

INSTALLATION_DIRS=	bin

do-extract:
	${CP} -Rp ${FILESDIR} ${WRKSRC}

do-build:
	${SED} -e 's|@PKGSRCDIR@|${PKGSRCDIR}|' \
		${WRKSRC}/pkgdep.pl > ${WRKDIR}/pkgdep

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/pkgdep ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
