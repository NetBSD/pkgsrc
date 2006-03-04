# $NetBSD: Makefile,v 1.2 2006/03/04 21:29:19 jlam Exp $
#

DISTNAME=	Cache-Memcached-1.14
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://danga.com/memcached/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://danga.com/memcached/
COMMENT=	Perl API module for memcached

DEPENDS+=	p5-String-CRC32-[0-9]*:../../textproc/p5-String-CRC32

PERL5_PACKLIST= auto/Cache/Memcached/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
