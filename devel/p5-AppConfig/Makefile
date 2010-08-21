# $NetBSD: Makefile,v 1.20 2010/08/21 16:33:11 seb Exp $

DISTNAME=	AppConfig-1.66
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5apc
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AppConfig/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/AppConfig/
COMMENT=	Perl5 module for parsing config files and command line arguments

DEPENDS+=	p5-File-HomeDir-[0-9]*:../../devel/p5-File-HomeDir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/AppConfig/.packlist

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
