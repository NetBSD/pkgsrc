# $NetBSD: Makefile,v 1.1.1.1 2009/05/17 10:29:11 sno Exp $
#

DISTNAME=	Moose-Policy-0.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/ST/STEVAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Moose-Policy/
COMMENT=	Moose-mounted police
LICENSE=	gnu-gpl-v2 # OR artistic

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Moose/Policy/.packlist

DEPENDS+=	p5-Moose>=0.42:../../devel/p5-Moose
DEPENDS+=	p5-Test-Exception>=0.21:../../devel/p5-Test-Exception

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
