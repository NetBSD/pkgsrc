# $NetBSD: Makefile,v 1.6 2013/05/31 12:42:12 wiz Exp $

DISTNAME=	Pod-Spell-1.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-Spell/
COMMENT=	Formatter for spellchecking Pod

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-Pod-Escapes>=1.01:../../textproc/p5-Pod-Escapes

PERL5_PACKLIST=		auto/Pod/Spell/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
