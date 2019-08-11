# $NetBSD: Makefile,v 1.14 2019/08/11 13:20:41 wiz Exp $

DISTNAME=	Tie-LLHash-1.004
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Tie-LLHash
COMMENT=	Ordered hashes
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Tie/LLHash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
