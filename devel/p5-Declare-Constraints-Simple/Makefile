# $NetBSD: Makefile,v 1.4 2011/08/12 06:56:59 adam Exp $

DISTNAME=	Declare-Constraints-Simple-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PH/PHAYLON/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Declare-Constraints-Simple/
COMMENT=	Perl 5 module for declarative validation of data structures
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Declare/Constraints/Simple/.packlist

DEPENDS+=	p5-Carp-Clan-[0-9]*:../../devel/p5-Carp-Clan
DEPENDS+=	p5-Class-Inspector-[0-9]*:../../devel/p5-Class-Inspector
DEPENDS+=	p5-aliased-[0-9]*:../../devel/p5-aliased

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
