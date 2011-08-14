# $NetBSD: Makefile,v 1.7 2011/08/14 12:26:26 obache Exp $

DISTNAME=	POE-Component-Pluggable-1.26
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=POE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/POE-Component-Pluggable/
COMMENT=	Perl base class for creating plugin enabled POE Components
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-POE>=1.004:../../devel/p5-POE
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken
DEPENDS+=	p5-constant>=1.17:../../devel/p5-constant

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/POE/Component/Pluggable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
