# $NetBSD: Makefile,v 1.15 2011/05/23 08:28:42 cheusov Exp $
#

DISTNAME=	pkgdep-1.0
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Script for displaying dependence information on software packages

PKG_DESTDIR_SUPPORT=	user-destdir

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
