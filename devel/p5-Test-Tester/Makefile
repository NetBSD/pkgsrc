# $NetBSD: Makefile,v 1.8 2012/01/26 12:55:13 rhaen Exp $

DISTNAME=		Test-Tester-0.108
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		rhaen@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Tester/
COMMENT=		Perl5 module to ease testing test modules built with Test::Builder

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/Tester/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
