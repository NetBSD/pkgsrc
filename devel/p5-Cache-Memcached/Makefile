# $NetBSD: Makefile,v 1.9 2010/08/21 16:33:16 seb Exp $
#

DISTNAME=	Cache-Memcached-1.28
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Cache/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://danga.com/memcached/
COMMENT=	Perl API for distributed memory cache daemon memcached
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-String-CRC32-[0-9]*:../../textproc/p5-String-CRC32
DEPENDS+=	{perl>=5.10,p5-Time-HiRes-[0-9]*}:../../time/p5-Time-HiRes

PERL5_PACKLIST= auto/Cache/Memcached/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
