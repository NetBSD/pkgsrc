# $NetBSD: Makefile,v 1.11 2009/04/24 15:05:16 sno Exp $
#

DISTNAME=	AnyEvent-4.352
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://www.cpan.org/modules/by-authors/Marc_Lehmann/

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://software.schmorp.de/pkg/AnyEvent.html
COMMENT=	Simple API for io, timer and completion callbacks

PKG_DESTDIR_SUPPORT=	user-destdir
PERL5_PACKLIST=	auto/AnyEvent/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
