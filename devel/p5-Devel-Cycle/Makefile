# $NetBSD: Makefile,v 1.11 2009/08/26 01:30:03 seb Exp $

DISTNAME=		Devel-Cycle-1.11
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Devel-Cycle/
COMMENT=		Perl5 module to find memory cycles in objects

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Devel/Cycle/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
