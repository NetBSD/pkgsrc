# $NetBSD: Makefile,v 1.1 2012/09/05 15:14:57 is Exp $

DISTNAME=	File-Slurp-Unicode-0.7.1
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5fslu
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	nobody
HOMEPAGE=	http://search.cpan.org/dist/File-Slurp-Unicode/
COMMENT=	Read/write/append files quickly
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/File/Slurp/Unicode/.packlist

DEPENDS	+=      	p5-File-Slurp:../../devel/p5-File-Slurp   

PERL5_MODULE_TYPE=      Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
