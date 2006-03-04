# $NetBSD: Makefile,v 1.7 2006/03/04 21:29:22 jlam Exp $
#

DISTNAME=	Memoize-ExpireLRU-0.55
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Memoize/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Expiry plug-in for Memoize that adds LRU cache expiration

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Memoize/ExpireLRU/.packlist

DEPENDS+=		p5-Memoize>=0.52:../../devel/p5-Memoize

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
