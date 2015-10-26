# $NetBSD: Makefile,v 1.22 2015/10/26 20:38:09 kamil Exp $
#

PKGNAME=	pkgdep-1.0
PKGREVISION=	5
CATEGORIES=	pkgtools

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Script for displaying dependence information on software packages

WRKSRC=		${WRKDIR}/files
USE_TOOLS+=	perl:run

BUILD_DEPENDS+=	p5-Perl4-CoreLibs-[0-9]*:../../devel/p5-Perl4-CoreLibs

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
