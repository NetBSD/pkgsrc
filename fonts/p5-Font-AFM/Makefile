# $NetBSD: Makefile,v 1.2 2002/10/07 22:34:26 seb Exp $

DISTNAME=		Font-AFM-1.18
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5fon
CATEGORIES=		fonts perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Font/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 modules for parsing PostScript font metrics files

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Font/AFM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
