# $NetBSD: Makefile,v 1.1.1.1 2005/06/24 17:20:53 wiz Exp $

DISTNAME=		File-Slurp-9999.09
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5fsl
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/File-Slurp/
COMMENT=		Read/write/append files quickly

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/File/Slurp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
