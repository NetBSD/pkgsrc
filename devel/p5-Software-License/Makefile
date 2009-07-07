# $NetBSD: Makefile,v 1.5 2009/07/07 21:26:19 sno Exp $
#

DISTNAME=	Software-License-0.012
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/R/RJ/RJBS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Software-License/
COMMENT=	Perl 5 module which provide templated software licenses
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Data-Section-[0-9]*:../../devel/p5-Data-Section
DEPENDS+=	p5-Sub-Install-[0-9]*:../../devel/p5-Sub-Install
DEPENDS+=	p5-Text-Template-[0-9]*:../../textproc/p5-Text-Template

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Software/License/.packlist
MAKE_PARAMS+=	--skipdeps # Can#t use Module::Install as type because ExtraTests.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
