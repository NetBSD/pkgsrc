# $NetBSD: Makefile,v 1.1 2014/11/01 03:33:56 wen Exp $

DISTNAME=	Devel-OverloadInfo-0.002
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-OverloadInfo/
COMMENT=	Perl 5 module for introspect overloaded operators
LICENSE=	${PERL5_LICENSE}

DEPENDS+=       p5-MRO-Compat>=0:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Sub-Identify>=0:../../devel/p5-Sub-Identify

PERL5_PACKLIST=	auto/Devel/OverloadInfo/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
