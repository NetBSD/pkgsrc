# $NetBSD: Makefile,v 1.21 2023/07/06 09:41:41 wiz Exp $

DISTNAME=	Net-IDN-Encode-2.500
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CF/CFAERBER/}
MASTER_SITES+=	${MASTER_SITE_PERL_CPAN:=Encode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-IDN-Encode
COMMENT=	IDN, Internationalized Domain Names (Encode, UTS46, Punycode)
LICENSE=	${PERL5_LICENSE}

TOOL_DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings

PERL5_REQD+=	5.7.3

PERL5_PACKLIST=	auto/Net/IDN/Encode/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
