# $NetBSD: Makefile,v 1.13 2008/10/19 19:17:57 he Exp $
#

DISTNAME=	Module-ScanDeps-0.84
PKGREVISION=	2
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5msd
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-ScanDeps/
COMMENT=	Perl 5 module to recursively scan Perl code for dependencies

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Module/ScanDeps/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-version-[0-9]*:../../devel/p5-version
DEPENDS+=	p5-Module-Build-[0-9]*:../../devel/p5-Module-Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
