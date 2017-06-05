# $NetBSD: Makefile,v 1.7 2017/06/05 14:22:52 ryoon Exp $

DISTNAME=	Devel-OverloadInfo-0.004
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-OverloadInfo/
COMMENT=	Perl 5 module for introspect overloaded operators
LICENSE=	${PERL5_LICENSE}

DEPENDS+=       p5-MRO-Compat>=0:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Sub-Identify>=0:../../devel/p5-Sub-Identify

BUILD_DEPENDS+=	p5-Package-Stash-[0-9]*:../../devel/p5-Package-Stash

PERL5_PACKLIST=	auto/Devel/OverloadInfo/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
