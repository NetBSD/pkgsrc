# $NetBSD: Makefile,v 1.3 2010/08/21 16:35:57 seb Exp $

DISTNAME=	Pod-Spell-CommonMistakes-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-Spell-CommonMistakes/
COMMENT=	Catches common typos in POD
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IO-stringy>=2.110:../../devel/p5-IO-stringy
DEPENDS+=	p5-Pod-Spell>=1.01:../../textproc/p5-Pod-Spell

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Pod/Spell/CommonMistakes/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
