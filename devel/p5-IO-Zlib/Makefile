# $NetBSD: Makefile,v 1.8 2005/04/11 21:45:32 tv Exp $

DISTNAME=		IO-Zlib-1.01
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5izl
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 IO:: style interface to Compress::Zlib

DEPENDS+=		p5-Compress-Zlib>=1.16:../../devel/p5-Compress-Zlib

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IO/Zlib/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
