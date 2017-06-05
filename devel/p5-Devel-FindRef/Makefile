# $NetBSD: Makefile,v 1.13 2017/06/05 14:22:52 ryoon Exp $

DISTNAME=	Devel-FindRef-1.44
PKGNAME=	p5-${DISTNAME}0
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-FindRef/
COMMENT=	Perl 5 module to track down references
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-common-sense-[0-9]*:../../devel/p5-common-sense

PERL5_PACKLIST=		auto/Devel/FindRef/.packlist

# see https://rt.cpan.org/Public/Bug/Display.html?id=101077
BROKEN=		Broken with perl-5.22.

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
