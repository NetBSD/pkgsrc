# $NetBSD: Makefile,v 1.12 2009/05/19 08:59:11 wiz Exp $
#

DISTNAME=	Date-Business-1.2
PKGNAME=	${DISTNAME:S/Date-Business/p5-Date-Business/}
PKGREVISION=	3
SVR4_PKGNAME=	p5dbu
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cpan.org/
COMMENT=	Perl5 module for fast calendar and business date calculations
LICENSE=	morganstanley-license

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Date/Business/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
