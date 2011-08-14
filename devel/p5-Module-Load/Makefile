# $NetBSD: Makefile,v 1.6 2011/08/14 12:26:18 obache Exp $

DISTNAME=	Module-Load-0.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5ml
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Load/
COMMENT=	Perl5 module to runtime require of both modules and files
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Module/Load/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
