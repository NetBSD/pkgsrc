# $NetBSD: Makefile,v 1.27 2019/06/30 20:16:41 nia Exp $

DISTNAME=	Digest-Hashcash-1.1
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Digest-Hashcash
COMMENT=	Perl5 extension module for hashcash hashes
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-Canary-Stability-[0-9]*:../../devel/p5-Canary-Stability

PERL5_PACKLIST=		auto/Digest/Hashcash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
