# $NetBSD: Makefile,v 1.1 2013/07/21 09:46:26 wen Exp $

DISTNAME=	MooX-Types-MooseLike-Numeric-1.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MA/MATEU/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooX-Types-MooseLike-Numeric/
COMMENT=	Moo types for numbers
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-MooX-Types-MooseLike>=0.23:../../devel/p5-Moo

PERL5_PACKLIST=	auto/MooX-Types-MooseLike-Numeric/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
