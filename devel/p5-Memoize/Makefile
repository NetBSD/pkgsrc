# $NetBSD: Makefile,v 1.18 2010/08/21 16:34:00 seb Exp $
#

DISTNAME=	Memoize-1.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5mem
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Memoize/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://perl.plover.com/Memoize/
COMMENT=	Transparently speed up functions by caching return values

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Memoize/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
