# $NetBSD: Makefile,v 1.8 2012/10/31 11:18:09 asau Exp $

DISTNAME=	File-DesktopEntry-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-DesktopEntry/
COMMENT=	Perl module for handling .desktop files
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-File-BaseDir>=0.03:../../devel/p5-File-BaseDir

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/File/DesktopEntry/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
