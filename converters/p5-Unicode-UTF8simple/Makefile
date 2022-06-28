# $NetBSD: Makefile,v 1.19 2022/06/28 11:31:12 wiz Exp $

DISTNAME=	Unicode-UTF8simple-1.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unicode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Unicode-UTF8simple
COMMENT=	Conversions to/from UTF8 from/to charactersets

PERL5_PACKLIST=	auto/Unicode/UTF8simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
