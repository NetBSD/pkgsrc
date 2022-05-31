# $NetBSD: Makefile,v 1.28 2022/05/31 21:03:08 markd Exp $

DISTNAME=	Term-ANSIColor-5.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RR/RRA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Term-ANSIColor
COMMENT=	Color screen output using ANSI escape sequences
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Term/ANSIColor/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
