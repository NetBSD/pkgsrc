# $NetBSD: Makefile,v 1.4 2011/08/14 12:26:42 obache Exp $
#

DISTNAME=	Test-Mock-LWP-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5 net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Mock-LWP/
COMMENT=	Perl 5 package providing easy mocking of LWP packages

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/Mock/LWP/.packlist

DEPENDS+=	p5-Test-MockObject>=1.08:../../devel/p5-Test-MockObject

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
