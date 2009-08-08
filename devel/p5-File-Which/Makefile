# $NetBSD: Makefile,v 1.3 2009/08/08 14:03:46 sno Exp $
#

DISTNAME=	File-Which-1.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Which/
COMMENT=	Portable implementation of the `which' utility
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=		p5-Test-Simple>=0.80:../../devel/p5-Test-Simple

PERL5_PACKLIST=		auto/File/Which/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
