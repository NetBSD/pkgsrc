# $NetBSD: Makefile,v 1.29 2023/07/06 09:39:20 wiz Exp $

DISTNAME=	IO-Digest-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=OurNet/CLKAO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/IO-Digest
COMMENT=	Perl module to calculate digests while reading or writing
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-PerlIO-via-dynamic-[0-9]*:../../devel/p5-PerlIO-via-dynamic

PERL5_PACKLIST=		auto/IO/Digest/.packlist

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
