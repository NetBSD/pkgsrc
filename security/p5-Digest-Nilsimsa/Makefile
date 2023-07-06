# $NetBSD: Makefile,v 1.33 2023/07/06 09:41:26 wiz Exp $

DISTNAME=	Digest-Nilsimsa-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	17
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Digest-Nilsimsa
COMMENT=	Perl5 extension module for Nilsimsa signatures
LICENSE=	gnu-gpl-v2

PERL5_PACKLIST=		auto/Digest/Nilsimsa/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
