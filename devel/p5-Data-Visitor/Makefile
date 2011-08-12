# $NetBSD: Makefile,v 1.13 2011/08/12 06:42:15 adam Exp $

DISTNAME=	Data-Visitor-0.27
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-Visitor/
COMMENT=	Visitor style traversal of Perl data structures
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose>=0.89:../../devel/p5-Moose
DEPENDS+=	p5-Task-Weaken>=0:../../devel/p5-Task-Weaken
DEPENDS+=	{perl>=5.10,p5-Test-Simple>=0}:../../devel/p5-Test-Simple
DEPENDS+=	p5-Test-use-ok>=0:../../devel/p5-Test-use-ok
DEPENDS+=	p5-Tie-ToObject>=0.01:../../devel/p5-Tie-ToObject
DEPENDS+=	p5-namespace-clean>=0.08:../../devel/p5-namespace-clean

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Data/Visitor/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
