# $NetBSD: Makefile,v 1.1.1.1 1998/12/05 03:28:48 tv Exp $
#

DISTNAME=		MLDBM-2.00
PKGNAME=		p5-MLDBM-2.00
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	MLDBM

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/MLDBM/MLDBM.html

BUILD_DEPENDS= 		${PREFIX}/lib/perl5/site_perl/Data/Dumper.pm:../../devel/p5-Data-Dumper
RUN_DEPENDS:=		${BUILD_DEPENDS}

USE_PERL5=		YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
