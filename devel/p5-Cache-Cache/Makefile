# $NetBSD: Makefile,v 1.32 2020/03/20 11:57:29 nia Exp $

DISTNAME=	Cache-Cache-1.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Cache/}
MASTER_SITES+=	${MASTER_SITE_SOURCEFORGE:=perl-cache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://perl-cache.sourceforge.net/
COMMENT=	The Cache interface
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Error>=0.15:../../devel/p5-Error
DEPENDS+=	p5-Digest-SHA1>=2.02:../../security/p5-Digest-SHA1
#DEPENDS+=	p5-Storable>=1.014:../../devel/p5-Storable
DEPENDS+=	p5-IPC-ShareLite>=0.09:../../devel/p5-IPC-ShareLite

USE_LANGUAGES=	# none

PERL5_PACKLIST=	auto/Cache/Cache/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
