# $NetBSD: Makefile,v 1.7 2012/10/03 11:43:41 asau Exp $
#

DISTNAME=	Padre-Plugin-PerlTidy-0.22
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	editors devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Padre/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Padre-Plugin-PerlTidy/
COMMENT=	Format perl files in Padre using Perl::Tidy
LICENSE=	${PERL5_LICENSE}

MAKE_JOBS_SAFE=	no

DEPENDS+=	p5-Padre>=0.92:../../editors/p5-Padre
DEPENDS+=	p5-Params-Util>=1.04:../../devel/p5-Params-Util
DEPENDS+=	p5-Perl-Tidy>=20101217:../../devel/p5-Perl-Tidy

PERL5_PACKLIST=		auto/Padre/Plugin/PerlTidy/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

#pre-configure:
#	cd ${WRKSRC} && find `pwd` -name "*.orig" -type f | xargs rm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
