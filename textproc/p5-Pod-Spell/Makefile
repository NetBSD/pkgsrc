# $NetBSD: Makefile,v 1.1.1.1 2008/11/09 13:28:53 obache Exp $

DISTNAME=	Pod-Spell-1.01
PKGNAME=	p5-${DISTNAME}
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
