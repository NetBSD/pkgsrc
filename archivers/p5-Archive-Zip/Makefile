# $NetBSD: Makefile,v 1.15 2005/04/11 21:44:49 tv Exp $

DISTNAME=		Archive-Zip-1.14
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5zip
PKGREVISION=		1
CATEGORIES=		archivers perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Archive/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Archive-Zip/
COMMENT=		Perl5 module interface to manipulate zip files

DEPENDS+=		p5-Compress-Zlib-[0-9]*:../../devel/p5-Compress-Zlib

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Archive/Zip/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
