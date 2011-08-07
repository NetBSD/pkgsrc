# $NetBSD: Makefile,v 1.5 2011/08/07 07:56:57 adam Exp $

DISTNAME=	AppConfig-Std-1.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AppConfig/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/AppConfig-Std/
COMMENT=	AppConfig::Std Perl module

PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/AppConfig/Std/.packlist

DEPENDS+=		p5-AppConfig>=1.52:../../devel/p5-AppConfig

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
