# $NetBSD: Makefile,v 1.22 2017/06/05 14:24:44 ryoon Exp $

DISTNAME=	Pod-Spell-1.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-Spell/
COMMENT=	Formatter for spellchecking Pod
LICENSE=	artistic-2.0

#DEPENDS+=	{perl>=5.9.3,p5-Pod-Escapes>=1.01}:../../textproc/p5-Pod-Escapes
DEPENDS+=	p5-Lingua-EN-Inflect>=0:../../textproc/p5-Lingua-EN-Inflect
DEPENDS+=	p5-Class-Tiny>=0:../../devel/p5-Class-Tiny
DEPENDS+=	p5-File-ShareDir>=0:../../devel/p5-File-ShareDir
DEPENDS+=	p5-File-ShareDir-Install>=0:../../devel/p5-File-ShareDir-Install

# for make test
BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep

PERL5_PACKLIST=		auto/Pod/Spell/.packlist

SUBST_CLASSES+=		perl
SUBST_STAGE.perl=	post-patch
SUBST_MESSAGE.perl=	Fixing path to perl
SUBST_FILES.perl+=	bin/podspell
SUBST_SED.perl=		-e "s|/usr/bin/env perl|${PERL5}|"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
