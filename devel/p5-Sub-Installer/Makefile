# $NetBSD: Makefile,v 1.7 2012/10/31 11:18:58 asau Exp $

DISTNAME=	Sub-Installer-v0.0.3
PKGNAME=	p5-Sub-Installer-0.0.3
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sub/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Sub-Installer/
COMMENT=	Perl 5 module prodiving a clean way to install package subroutines
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-version-[0-9]*:../../devel/p5-version

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Sub/Installer/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
