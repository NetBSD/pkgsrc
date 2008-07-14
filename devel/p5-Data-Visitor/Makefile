# $NetBSD: Makefile,v 1.1.1.1 2008/07/14 09:24:35 abs Exp $

DISTNAME=	Data-Visitor-0.15
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-Visitor/
COMMENT=	Visitor style traversal of Perl data structures

DEPENDS+=	p5-Class-Accessor>=0:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Tie-ToObject>=0.01:../../devel/p5-Tie-ToObject
BUILD_DEPENDS+=	p5-Test-use-ok>=0:../../devel/p5-Test-use-ok
BUILD_DEPENDS+=	p5-Test-MockObject>=1.04:../../devel/p5-Test-MockObject

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Data/Visitor/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
