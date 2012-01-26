# $NetBSD: Makefile,v 1.23 2012/01/26 15:59:16 rhaen Exp $

DISTNAME=		Test-Pod-1.45
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tp
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Pod/
COMMENT=		Perl5 module to check for POD errors in files
LICENSE=		artistic-2.0 OR gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		{perl>=5.10.1,p5-Pod-Simple>=3.07}:../../textproc/p5-Pod-Simple
DEPENDS+=		{p5-Test-Simple>=0.70,perl>=5.8.9}:../../devel/p5-Test-Simple

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/Pod/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
