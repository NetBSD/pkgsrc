# $NetBSD: Makefile,v 1.7 2009/04/29 20:42:09 abs Exp $

DISTNAME=	Data-Visitor-0.24
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-Visitor/
COMMENT=	Visitor style traversal of Perl data structures

DEPENDS+=	p5-Any-Moose>=0.07:../../devel/p5-Any-Moose
DEPENDS+=	p5-namespace-clean>=0.08:../../devel/p5-namespace-clean
DEPENDS+=	p5-Test-MockObject>=1.04:../../devel/p5-Test-MockObject
DEPENDS+=	p5-Test-Simple>=0:../../devel/p5-Test-Simple
DEPENDS+=	p5-Test-use-ok>=0:../../devel/p5-Test-use-ok
DEPENDS+=	p5-Tie-ToObject>=0.01:../../devel/p5-Tie-ToObject
DEPENDS+=	p5-Data-Alias>=0:../../devel/p5-Data-Alias
DEPENDS+=	p5-Task-Weaken>=0:../../devel/p5-Task-Weaken

PERL5_PACKLIST=	auto/Data/Visitor/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
