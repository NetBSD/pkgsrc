# $NetBSD: Makefile,v 1.1 2012/08/06 13:44:39 wen Exp $

DISTNAME=		Test-Number-Delta-1.03
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		math perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		wen@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Number-Delta
COMMENT=		Compare the difference between numbers against a given tolerance
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Test/Number/Delta/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
