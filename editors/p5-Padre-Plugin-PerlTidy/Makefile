# $NetBSD: Makefile,v 1.16 2019/06/30 20:16:07 nia Exp $
#

DISTNAME=	Padre-Plugin-PerlTidy-0.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	editors devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Padre/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Padre-Plugin-PerlTidy
COMMENT=	Format perl files in Padre using Perl::Tidy
LICENSE=	${PERL5_LICENSE}

MAKE_JOBS_SAFE=	no

DEPENDS+=	p5-Padre>=0.92:../../editors/p5-Padre
DEPENDS+=	p5-Params-Util>=1.04:../../devel/p5-Params-Util
DEPENDS+=	p5-Perl-Tidy>=20101217:../../devel/p5-Perl-Tidy

PERL5_PACKLIST=		auto/Padre/Plugin/PerlTidy/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

#pre-configure:
#	cd ${WRKSRC} && find `pwd` -name "*.orig" -type f | xargs rm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
