# $NetBSD: Makefile,v 1.5 2002/10/20 17:46:03 seb Exp $

DISTNAME=		Archive-Zip-0.11
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5zip
CATEGORIES=		archivers perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Archive/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 module interface to manipulate zip files

DEPENDS+=		p5-Compress-Zlib-[0-9]*:../../devel/p5-Compress-Zlib

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Archive/Zip/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
