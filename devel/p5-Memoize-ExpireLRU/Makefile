# $NetBSD: Makefile,v 1.12 2011/08/14 12:26:16 obache Exp $
#

DISTNAME=	Memoize-ExpireLRU-0.55
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Memoize/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Expiry plug-in for Memoize that adds LRU cache expiration

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Memoize/ExpireLRU/.packlist

DEPENDS+=		{perl>=5.7.3,p5-Memoize>=0.52}:../../devel/p5-Memoize

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
