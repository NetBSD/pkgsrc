# $NetBSD: Makefile,v 1.8 2017/06/05 14:22:34 ryoon Exp $

DISTNAME=	Algorithm-Permute-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Algorithm-Permute/
COMMENT=	Perl module for generating permutations with object oriented interface
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Algorithm/Permute/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
