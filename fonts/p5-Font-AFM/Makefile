# $NetBSD: Makefile,v 1.4 2003/07/17 21:37:33 grant Exp $

DISTNAME=		Font-AFM-1.18
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5fon
CATEGORIES=		fonts perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Font/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		perl5 modules for parsing PostScript font metrics files

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Font/AFM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
