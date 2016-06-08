# $NetBSD: Makefile,v 1.20 2016/06/08 19:23:09 wiz Exp $
#

DISTNAME=	Memoize-ExpireLRU-0.55
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Memoize/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Expiry plug-in for Memoize that adds LRU cache expiration

PERL5_PACKLIST=		auto/Memoize/ExpireLRU/.packlist

#DEPENDS+=		{perl>=5.7.3,p5-Memoize>=0.52}:../../devel/p5-Memoize

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
