# $NetBSD: Makefile,v 1.15 2023/07/06 09:38:16 wiz Exp $

DISTNAME=	Unicode-EastAsianWidth-12.0
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unicode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Unicode-EastAsianWidth
COMMENT=	Perl5 module that provides properties of East Asian characters
LICENSE=	cc0-1.0-universal

PERL5_PACKLIST=	auto/Unicode/EastAsianWidth/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
