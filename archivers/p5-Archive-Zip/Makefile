# $NetBSD: Makefile,v 1.8 2003/07/21 16:24:40 martti Exp $

DISTNAME=		Archive-Zip-0.11
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5zip
CATEGORIES=		archivers perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Archive/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 module interface to manipulate zip files

DEPENDS+=		p5-Compress-Zlib-[0-9]*:../../devel/p5-Compress-Zlib

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Archive/Zip/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
