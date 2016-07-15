# $NetBSD: Makefile,v 1.21 2016/07/15 12:28:37 wen Exp $
#

DISTNAME=	Memoize-ExpireLRU-0.56
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Memoize/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Expiry plug-in for Memoize that adds LRU cache expiration
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Memoize/ExpireLRU/.packlist

#DEPENDS+=		{perl>=5.7.3,p5-Memoize>=0.52}:../../devel/p5-Memoize

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
