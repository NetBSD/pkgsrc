# $NetBSD: Makefile,v 1.7 2006/03/04 21:29:21 jlam Exp $

DISTNAME=	IO-Digest-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=OurNet/CLKAO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl module to calculate digests while reading or writing

DEPENDS+=	p5-PerlIO-via-dynamic-[0-9]*:../../devel/p5-PerlIO-via-dynamic

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/IO/Digest/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
