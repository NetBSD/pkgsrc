# $NetBSD: Makefile,v 1.28 2023/07/06 09:39:29 wiz Exp $
#

DISTNAME=	Memoize-ExpireLRU-0.56
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Memoize/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Expiry plug-in for Memoize that adds LRU cache expiration
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Memoize/ExpireLRU/.packlist

#DEPENDS+=		{perl>=5.7.3,p5-Memoize>=0.52}:../../devel/p5-Memoize

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
