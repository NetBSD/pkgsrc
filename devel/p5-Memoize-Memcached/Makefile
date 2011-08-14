# $NetBSD: Makefile,v 1.3 2011/08/14 12:26:17 obache Exp $

DISTNAME=	Memoize-Memcached-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Memoize/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist//Memoize-Memcached/
COMMENT=	Use a memcached cache to memoize functions
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Cache-Memcached-[0-9]*:../../devel/p5-Cache-Memcached

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Memoize/Memcached/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
