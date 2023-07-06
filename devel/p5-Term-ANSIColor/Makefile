# $NetBSD: Makefile,v 1.30 2023/07/06 09:40:06 wiz Exp $

DISTNAME=	Term-ANSIColor-5.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RR/RRA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Term-ANSIColor
COMMENT=	Color screen output using ANSI escape sequences
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Term/ANSIColor/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
