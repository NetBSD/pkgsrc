# $NetBSD: Makefile,v 1.1.1.1 2012/02/25 05:15:27 obache Exp $
#

DISTNAME=	Check-ISA-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/N/NU/NUFFIN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Check-ISA/
COMMENT=	DWIM, correct checking of an object's class
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-Test-use-ok-[0-9]*:../../devel/p5-Test-use-ok

PERL5_PACKLIST=	auto/Check/ISA/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
