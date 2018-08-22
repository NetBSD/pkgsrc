# $NetBSD: Makefile,v 1.9 2018/08/22 09:44:22 wiz Exp $
#

DISTNAME=	MooseX-CompileTime-Traits-1.102570
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-CompileTime-Traits/
COMMENT=	Allow compile time traits for classes/roles
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Declare-[0-9]*:../../devel/p5-MooseX-Declare

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/CompileTime/Traits/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
