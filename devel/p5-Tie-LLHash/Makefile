# $NetBSD: Makefile,v 1.18 2023/07/06 09:40:23 wiz Exp $

DISTNAME=	Tie-LLHash-1.004
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Tie-LLHash
COMMENT=	Ordered hashes
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Tie/LLHash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
