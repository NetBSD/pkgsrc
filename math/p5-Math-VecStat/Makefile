# $NetBSD: Makefile,v 1.3 2011/08/14 13:38:23 obache Exp $
#

DISTNAME=	Math-VecStat-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Math-VecStat/
COMMENT=	Some basic numeric stats on vectors

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Math/VecStat/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
