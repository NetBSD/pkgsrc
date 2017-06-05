# $NetBSD: Makefile,v 1.22 2017/06/05 14:22:39 ryoon Exp $

DISTNAME=	Cache-FastMmap-1.45
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Cache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Cache-FastMmap/
COMMENT=	Shared memory cache through an mmap'ed file
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Cache/FastMmap/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
