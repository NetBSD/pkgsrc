# $NetBSD: Makefile,v 1.5 2006/05/05 17:50:49 abs Exp $

DISTNAME=		File-Slurp-9999.12
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5fsl
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/File-Slurp/
COMMENT=		Read/write/append files quickly

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/File/Slurp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
