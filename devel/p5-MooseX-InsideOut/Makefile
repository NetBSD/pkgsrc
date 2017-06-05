# $NetBSD: Makefile,v 1.14 2017/06/05 14:23:20 ryoon Exp $
#

DISTNAME=	MooseX-InsideOut-0.106
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-InsideOut/
COMMENT=	Perl 5 module providing inside-out objects with Moose
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/InsideOut/.packlist

DEPENDS+=	p5-Hash-Util-FieldHash-Compat-[0-9]*:../../devel/p5-Hash-Util-FieldHash-Compat
DEPENDS+=	p5-Moose>=2:../../devel/p5-Moose
DEPENDS+=	p5-namespace-clean>=0.11:../../devel/p5-namespace-clean

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
