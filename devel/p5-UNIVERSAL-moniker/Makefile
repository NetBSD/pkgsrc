# $NetBSD: Makefile,v 1.12 2011/08/14 12:26:47 obache Exp $

DISTNAME=	UNIVERSAL-moniker-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
SVR4_PKGNAME=	p5cdi
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=UNIVERSAL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/UNIVERSAL-moniker/
COMMENT=	Perl module for assigning user-friendly names to classes

DEPENDS+=	p5-Lingua-EN-Inflect>=1.88:../../textproc/p5-Lingua-EN-Inflect

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/UNIVERSAL/moniker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
