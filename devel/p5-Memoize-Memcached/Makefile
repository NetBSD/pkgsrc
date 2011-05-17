# $NetBSD: Makefile,v 1.1.1.1 2011/05/17 10:50:11 dmcmahill Exp $

DISTNAME=	Memoize-Memcached-0.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DT/DTRISCHUK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist//Memoize-Memcached/
COMMENT=	Use a memcached cache to memoize functions
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Cache-Memcached:../../devel/p5-Cache-Memcached

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Memoize/Memcached/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
