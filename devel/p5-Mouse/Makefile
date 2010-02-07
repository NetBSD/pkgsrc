# $NetBSD: Makefile,v 1.21 2010/02/07 16:07:01 wiz Exp $

DISTNAME=	Mouse-0.49
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/G/GF/GFUJI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Mouse/
COMMENT=	Perl module implementing an extension of the perl object system
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Exception>=0.27:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Simple>=0.88:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-ExtUtils-ParseXS>=2.21:../../devel/p5-ExtUtils-ParseXS
BUILD_DEPENDS+=	p5-Devel-PPPort-[0-9]*:../../devel/p5-Devel-PPPort

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=	no

PERL5_PACKLIST=	auto/Mouse/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
