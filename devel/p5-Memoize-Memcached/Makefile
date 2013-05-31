# $NetBSD: Makefile,v 1.6 2013/05/31 12:40:29 wiz Exp $

DISTNAME=	Memoize-Memcached-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Memoize/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist//Memoize-Memcached/
COMMENT=	Use a memcached cache to memoize functions
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Cache-Memcached-[0-9]*:../../devel/p5-Cache-Memcached

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Memoize/Memcached/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
