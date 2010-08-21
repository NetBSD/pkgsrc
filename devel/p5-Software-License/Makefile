# $NetBSD: Makefile,v 1.7 2010/08/21 16:34:25 seb Exp $
#

DISTNAME=	Software-License-0.101620
PKGNAME=	p5-Software-License-0.101.620
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/R/RJ/RJBS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Software-License/
COMMENT=	Perl 5 module which provide templated software licenses
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple
DEPENDS+=	p5-Data-Section-[0-9]*:../../devel/p5-Data-Section
DEPENDS+=	p5-Sub-Install-[0-9]*:../../devel/p5-Sub-Install
DEPENDS+=	p5-Text-Template-[0-9]*:../../textproc/p5-Text-Template

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Software/License/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
