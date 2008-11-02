# $NetBSD: Makefile,v 1.5 2008/11/02 19:19:36 he Exp $

DISTNAME=	Data-Visitor-0.21
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-Visitor/
COMMENT=	Visitor style traversal of Perl data structures

DEPENDS+=	p5-Mouse>=0.06:../../devel/p5-Mouse
DEPENDS+=	p5-namespace-clean>=0.08:../../devel/p5-namespace-clean
DEPENDS+=	p5-Class-Accessor>=0:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Tie-ToObject>=0.01:../../devel/p5-Tie-ToObject
DEPENDS+=	p5-Data-Alias>=0:../../devel/p5-Data-Alias
DEPENDS+=	p5-Task-Weaken>=0:../../devel/p5-Task-Weaken
DEPENDS+=	p5-Test-MockObject>=1.04:../../devel/p5-Test-MockObject
DEPENDS+=	p5-Test-use-ok>=0:../../devel/p5-Test-use-ok

PERL5_PACKLIST=	auto/Data/Visitor/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
