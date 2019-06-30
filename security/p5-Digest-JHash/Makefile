# $NetBSD: Makefile,v 1.10 2019/06/30 20:16:41 nia Exp $

DISTNAME=		Digest-JHash-0.10
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Digest-JHash
COMMENT=		Perl extension for 32 bit Jenkins Hashing Algorithm
LICENSE=		artistic-2.0

PERL5_PACKLIST=		auto/Digest/JHash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
