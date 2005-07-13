# $NetBSD: Makefile,v 1.7 2005/07/13 18:01:22 jlam Exp $
#

DISTNAME=	Cache-Cache-1.03
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cc
PKGREVISION=	1
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

PERL5_PACKLIST=	auto/Cache/Cache/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
