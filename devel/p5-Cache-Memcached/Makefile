# $NetBSD: Makefile,v 1.1.1.1 2006/02/23 03:56:22 grant Exp $
#

DISTNAME=	Cache-Memcached-1.14
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://danga.com/memcached/dist/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://danga.com/memcached/
COMMENT=	Perl API module for memcached

DEPENDS+=	p5-String-CRC32-[0-9]*:../../textproc/p5-String-CRC32

PERL5_PACKLIST= auto/Cache/Memcached/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
