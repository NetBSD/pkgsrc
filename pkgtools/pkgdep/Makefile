# $NetBSD: Makefile,v 1.24 2016/07/09 06:38:48 wiz Exp $
#

PKGNAME=	pkgdep-1.0
PKGREVISION=	6
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
