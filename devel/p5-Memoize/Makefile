# $NetBSD: Makefile,v 1.5 2002/10/13 22:22:46 seb Exp $
#

DISTNAME=	Memoize-0.65
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mem
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Memoize/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://perl.plover.com/
COMMENT=	Transparently speed up functions by caching return values

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Memoize/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
