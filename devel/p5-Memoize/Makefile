# $NetBSD: Makefile,v 1.7 2003/06/02 01:20:25 jschauma Exp $
#

DISTNAME=	Memoize-1.01
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mem
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Memoize/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://perl.plover.com/
COMMENT=	Transparently speed up functions by caching return values

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Memoize/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
