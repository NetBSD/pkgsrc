# $NetBSD: Makefile,v 1.11 2013/10/27 11:49:50 wen Exp $

DISTNAME=	autobox-2.82
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=autobox/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/autobox/
COMMENT=	Perl 5 module to add methods on native types
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/autobox/.packlist

DEPENDS+=	p5-Scope-Guard>=0.20:../../devel/p5-Scope-Guard

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
