# $NetBSD: Makefile,v 1.14 2016/06/08 19:22:39 wiz Exp $

DISTNAME=	Class-C3-Adopt-NEXT-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-C3-Adopt-NEXT/
COMMENT=	Perl5 module to make NEXT suck less
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Exception>=0.27:../../devel/p5-Test-Exception
DEPENDS+=	p5-Scalar-List-Utils-[0-9]*:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat

MAKE_PARAMS+=		--skipdeps
PERL5_MODULE_TYPE=	Module::Install::Bundled
PERL5_PACKLIST=		auto/Class/C3/Adopt/NEXT/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
