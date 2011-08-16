# $NetBSD: Makefile,v 1.12 2011/08/16 07:00:59 adam Exp $

DISTNAME=	File-Slurp-9999.19
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5fsl
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/File-Slurp/
COMMENT=	Read/write/append files quickly
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/File/Slurp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
