# $NetBSD: Makefile,v 1.2 2010/08/21 16:35:58 seb Exp $

DISTNAME=	Pod-Spell-1.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-Spell/
COMMENT=	Formatter for spellchecking Pod

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Pod-Escapes>=1.01:../../textproc/p5-Pod-Escapes

PERL5_PACKLIST=		auto/Pod/Spell/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
