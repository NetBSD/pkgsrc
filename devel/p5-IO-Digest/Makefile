# $NetBSD: Makefile,v 1.17 2014/05/29 23:35:58 wiz Exp $

DISTNAME=	IO-Digest-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=OurNet/CLKAO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-Digest/
COMMENT=	Perl module to calculate digests while reading or writing
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-PerlIO-via-dynamic-[0-9]*:../../devel/p5-PerlIO-via-dynamic

PERL5_PACKLIST=		auto/IO/Digest/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
