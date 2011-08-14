# $NetBSD: Makefile,v 1.4 2011/08/14 12:26:21 obache Exp $
#

DISTNAME=	MooseX-Meta-TypeConstraint-ForceCoercion-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-Meta-TypeConstraint-ForceCoercion/
COMMENT=	Perl 5 module providing forced coercion validating type constraints
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/Meta/TypeConstraint/ForceCoercion/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
