# $NetBSD: Makefile,v 1.25 2026/09/25 08:53:32 wiz Exp $

DISTNAME=	Net-IDN-Encode-2.502
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RR/RRWO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-IDN-Encode
COMMENT=	IDN, Internationalized Domain Names (Encode, UTS46, Punycode)
LICENSE=	${PERL5_LICENSE}

TOOL_DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings

PERL5_PACKLIST=	auto/Net/IDN/Encode/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
