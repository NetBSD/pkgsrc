# $NetBSD: Makefile,v 1.15 2019/06/30 20:16:49 nia Exp $

DISTNAME=	Encode-Locale-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Encode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Encode-Locale
COMMENT=	Determine the locale encoding for Encode
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Encode/Locale/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
