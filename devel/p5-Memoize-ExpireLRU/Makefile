# $NetBSD: Makefile,v 1.1.1.1 2003/12/19 06:45:19 grant Exp $
#

DISTNAME=	Memoize-ExpireLRU-0.55
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Memoize/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Expiry plug-in for Memoize that adds LRU cache expiration

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Memoize/ExpireLRU/.packlist

DEPENDS+=		p5-Memoize>=0.52:../../devel/p5-Memoize

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
