# $NetBSD: Makefile,v 1.14 2012/10/31 11:18:09 asau Exp $

DISTNAME=	File-BaseDir-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-BaseDir/
COMMENT=	Perl module for the XDG Base Directory Specification
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/File/BaseDir/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
