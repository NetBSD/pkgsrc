# $NetBSD: Makefile,v 1.3 2004/04/25 04:15:34 minskim Exp $
#

DISTNAME=	Cache-Cache-1.02
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cc
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Cache/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://perl-cache.sourceforge.net/
COMMENT=	The Cache interface

DEPENDS+=	p5-Error>=0.15:../../devel/p5-Error
DEPENDS+=	p5-Digest-SHA1>=2.02:../../security/p5-Digest-SHA1
DEPENDS+=	p5-Storable>=1.014:../../devel/p5-Storable
DEPENDS+=	p5-IPC-ShareLite>=0.09:../../devel/p5-IPC-ShareLite

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Cache/Cache/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
