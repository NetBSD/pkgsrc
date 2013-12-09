# $NetBSD: Makefile,v 1.8 2013/12/09 14:17:53 obache Exp $

DISTNAME=	Pod-Spell-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-Spell/
COMMENT=	Formatter for spellchecking Pod
LICENSE=	artistic-2.0

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	{perl>=5.9.3,p5-Pod-Escapes>=1.01}:../../textproc/p5-Pod-Escapes

PERL5_PACKLIST=		auto/Pod/Spell/.packlist

SUBST_CLASSES+=		perl
SUBST_STAGE.perl=	post-patch
SUBST_MESSAGE.perl=	Fixing path to perl
SUBST_FILES.perl+=	bin/podspell
SUBST_SED.perl=		-e "s|/usr/bin/env perl|${PERL5}|"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
