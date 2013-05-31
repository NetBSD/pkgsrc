# $NetBSD: Makefile,v 1.6 2013/05/31 12:40:14 wiz Exp $

DISTNAME=	Devel-Autoflush-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-Autoflush/
COMMENT=	Perl module to set autoflush from the command line
LICENSE=	apache-2.0

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Devel/Autoflush/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
