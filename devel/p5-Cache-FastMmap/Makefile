# $NetBSD: Makefile,v 1.7 2009/07/07 20:51:51 sno Exp $

DISTNAME=	Cache-FastMmap-1.34
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cfm
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Cache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Cache-FastMmap/
COMMENT=	Shared memory cache through an mmap'ed file
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Cache/FastMmap/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
