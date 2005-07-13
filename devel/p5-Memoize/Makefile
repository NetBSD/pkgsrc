# $NetBSD: Makefile,v 1.13 2005/07/13 18:01:27 jlam Exp $
#

DISTNAME=	Memoize-1.01
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mem
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Memoize/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://perl.plover.com/Memoize/
COMMENT=	Transparently speed up functions by caching return values

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Memoize/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
