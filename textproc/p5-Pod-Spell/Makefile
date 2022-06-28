# $NetBSD: Makefile,v 1.30 2022/06/28 11:36:23 wiz Exp $

DISTNAME=	Pod-Spell-1.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Pod-Spell
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

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
