# $NetBSD: Makefile,v 1.20 2023/07/06 09:38:37 wiz Exp $

DISTNAME=	Array-Diff-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Array/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Array-Diff
COMMENT=	Perl 5 module to diff two arrays
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Algorithm-Diff>1.19:../../devel/p5-Algorithm-Diff
DEPENDS+=	p5-Class-Accessor>0:../../devel/p5-Class-Accessor

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Array/Diff/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
