# $NetBSD: Makefile,v 1.19 2022/06/28 11:33:48 wiz Exp $

DISTNAME=	Padre-Plugin-XS-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	editors perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Padre/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Padre-Plugin-XS
COMMENT=	Padre support for perl XS (and perlapi)
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Padre>=0.49:../../editors/p5-Padre
DEPENDS+=	p5-Locale-Msgfmt-[0-9]*:../../devel/p5-Locale-Msgfmt
DEPENDS+=	p5-Perl-APIReference>=0.04:../../devel/p5-Perl-APIReference
DEPENDS+=	p5-Software-License-[0-9]*:../../devel/p5-Software-License
DEPENDS+=	p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp
DEPENDS+=	p5-File-Find-Rule-Perl-[0-9]*:../../devel/p5-File-Find-Rule-Perl
# TEST_DEPENDS
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires

PERL5_PACKLIST=		auto/Padre/Plugin/XS/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
# blib/lib/auto/share/dist/Padre-Plugin-XS/locale isn't a directory at /usr/pkg/lib/perl5/vendor_perl/5.34.0/Locale/Msgfmt.pm line 21
MAKE_JOBS_SAFE=	no

#pre-configure:
#	cd ${WRKSRC} && find `pwd` -name "*.orig" -type f | xargs rm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
