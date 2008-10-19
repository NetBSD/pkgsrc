# $NetBSD: Makefile,v 1.10 2008/10/19 19:17:51 he Exp $

DISTNAME=		Devel-Cycle-1.10
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Devel-Cycle/
COMMENT=		Perl5 module to find memory cycles in objects

PERL5_PACKLIST=		auto/Devel/Cycle/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
