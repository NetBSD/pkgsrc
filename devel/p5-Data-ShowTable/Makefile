# $NetBSD: Makefile,v 1.6 2002/10/13 22:22:54 seb Exp $
#

DISTNAME=		Data-ShowTable-3.3
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5dst
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=		bad@netbsd.org
COMMENT=		Perl module to print arrays of data in nicely formatted listings

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Data/ShowTable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
