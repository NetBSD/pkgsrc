# $NetBSD: Makefile,v 1.2 1999/04/15 20:39:41 tron Exp $
#

DISTNAME=		MLDBM-2.00
PKGNAME=		p5-MLDBM-2.00
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=MLDBM/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/MLDBM/MLDBM.html

BUILD_DEPENDS= 		${PREFIX}/lib/perl5/site_perl/Data/Dumper.pm:../../devel/p5-Data-Dumper
RUN_DEPENDS:=		${BUILD_DEPENDS}

USE_PERL5=		YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
