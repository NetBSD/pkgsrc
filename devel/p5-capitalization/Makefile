# $NetBSD: Makefile,v 1.21 2023/07/06 09:40:27 wiz Exp $

DISTNAME=	capitalization-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	16
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MI/MIYAGAWA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/capitalization
COMMENT=	Perl module for no capitalization on method names

DEPENDS+=	p5-Devel-Symdump-[0-9]*:../../devel/p5-Devel-Symdump

PERL5_PACKLIST=		auto/capitalization/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
