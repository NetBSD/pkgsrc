# $NetBSD: Makefile,v 1.19 2023/07/06 09:40:01 wiz Exp $
#

DISTNAME=	Sort-Maker-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	15
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sort/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Sort-Maker
COMMENT=	Perl 5 module providing a simple way to make efficient sort subs

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Sort/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
