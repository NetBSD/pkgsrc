# $NetBSD: Makefile,v 1.21 2017/06/05 14:23:06 ryoon Exp $

DISTNAME=	IO-Digest-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=OurNet/CLKAO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-Digest/
COMMENT=	Perl module to calculate digests while reading or writing
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-PerlIO-via-dynamic-[0-9]*:../../devel/p5-PerlIO-via-dynamic

PERL5_PACKLIST=		auto/IO/Digest/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
