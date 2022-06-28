# $NetBSD: Makefile,v 1.29 2022/06/28 11:35:25 wiz Exp $
#

PKGNAME=	pkgdep-1.0
PKGREVISION=	11
CATEGORIES=	pkgtools

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Script for displaying dependence information on software packages

WRKSRC=		${WRKDIR}/files
USE_TOOLS+=	perl:run

DEPENDS+=	p5-Perl4-CoreLibs-[0-9]*:../../devel/p5-Perl4-CoreLibs

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
