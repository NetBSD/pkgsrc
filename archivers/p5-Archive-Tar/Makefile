# $NetBSD: Makefile,v 1.9 2004/03/11 18:03:50 xtraeme Exp $

DISTNAME=		Archive-Tar-1.02
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tar
CATEGORIES=		archivers perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Archive/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 module interface to manipulate tar files

DEPENDS+=		p5-IO-Zlib-[0-9]*:../../devel/p5-IO-Zlib

USE_BUILDLINK5=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Archive/Tar/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
