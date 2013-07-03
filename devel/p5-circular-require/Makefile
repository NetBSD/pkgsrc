# $NetBSD: Makefile,v 1.1 2013/07/03 08:41:29 sno Exp $

DISTNAME=	circular-require-0.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DO/DOY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/circular-require/
COMMENT=	Perl5 module to detect circularity in use/require statements
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Package-Stash-[0-9]*:../../devel/p5-Package-Stash

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/circular/require/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
