# $NetBSD: Makefile,v 1.4 2012/10/03 21:57:54 wiz Exp $
#

DISTNAME=		Number-Spell-0.04
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Number/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Number-Spell/
COMMENT=		Perl extension for spelling out numbers

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Number/Spell/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
