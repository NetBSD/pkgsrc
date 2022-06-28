# $NetBSD: Makefile,v 1.19 2022/06/28 11:36:15 wiz Exp $

DISTNAME=	Encode-Locale-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Encode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Encode-Locale
COMMENT=	Determine the locale encoding for Encode
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Encode/Locale/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
