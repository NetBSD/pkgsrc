# $NetBSD: Makefile,v 1.26 2014/10/09 13:44:37 wiz Exp $

DISTNAME=	AppConfig-1.66
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
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
