# $NetBSD: Makefile,v 1.30 2010/02/07 16:04:17 wiz Exp $
#

DISTNAME=	Date-Manip-6.07
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dma
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Date-Manip/
COMMENT=	Perl5 module for date calculations
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod
DEPENDS+=	p5-Test-Pod-Coverage-[0-9]*:../../devel/p5-Test-Pod-Coverage
DEPENDS+=	p5-YAML-Syck-[0-9]*:../../textproc/p5-YAML-Syck

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/Date/Manip/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
