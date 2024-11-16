# $NetBSD: Makefile,v 1.20 2024/11/16 12:03:19 wiz Exp $

DISTNAME=	Unicode-Map-0.112
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	16
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unicode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Unicode-Map
COMMENT=	Perl5 module that maps charsets from and to utf16 unicode

PERL5_PACKLIST=	auto/Unicode/Map/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
