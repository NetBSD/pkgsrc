# $NetBSD: Makefile,v 1.12 2017/06/05 14:22:36 ryoon Exp $

DISTNAME=	Array-Diff-0.07
PKGNAME=	p5-${DISTNAME:S/05002/05.002/}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Array/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Array-Diff/
COMMENT=	Perl 5 module to diff two arrays
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Algorithm-Diff>1.19:../../devel/p5-Algorithm-Diff
DEPENDS+=	p5-Class-Accessor>0:../../devel/p5-Class-Accessor

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Array/Diff/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
