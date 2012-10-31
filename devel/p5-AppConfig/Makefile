# $NetBSD: Makefile,v 1.23 2012/10/31 11:17:38 asau Exp $

DISTNAME=	AppConfig-1.66
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5apc
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AppConfig/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/AppConfig/
COMMENT=	Perl5 module for parsing config files and command line arguments
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-HomeDir-[0-9]*:../../devel/p5-File-HomeDir

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/AppConfig/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
