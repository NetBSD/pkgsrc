# $NetBSD: Makefile,v 1.16 2014/05/29 23:36:03 wiz Exp $
#

DISTNAME=	Memoize-ExpireLRU-0.55
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Memoize/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Expiry plug-in for Memoize that adds LRU cache expiration

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Memoize/ExpireLRU/.packlist

DEPENDS+=		{perl>=5.7.3,p5-Memoize>=0.52}:../../devel/p5-Memoize

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
