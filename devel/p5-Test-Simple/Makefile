# $NetBSD: Makefile,v 1.37 2007/12/11 11:59:23 rhaen Exp $

DISTNAME=		Test-Simple-0.74
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tsi
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		rhaen@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Simple/
COMMENT=		Perl5 module with a simple framework for writing tests

CONFLICTS+=		p5-Test-Builder-Tester-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Test/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
