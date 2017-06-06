# $NetBSD: Makefile,v 1.28 2017/06/06 20:40:56 wiz Exp $

DISTNAME=		GnuPG-Interface-0.52
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=GnuPG/}

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://gnupg-interface.sourceforge.net/
HOMEPAGE=		http://search.cpan.org/dist/GnuPG-Interface/
COMMENT=		Perl interface to GnuPG
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Moo-[0-9]*:../../devel/p5-Moo
DEPENDS+=		p5-MooX-late-[0-9]*:../../devel/p5-MooX-late
DEPENDS+=		p5-MooX-HandlesVia-[0-9]*:../../devel/p5-MooX-HandlesVia

PERL5_PACKLIST=		auto/GnuPG/Interface/.packlist

.include "options.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
