# $NetBSD: Makefile,v 1.3 2005/08/06 06:19:10 jlam Exp $

DISTNAME=		File-Slurp-9999.09
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5fsl
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/File-Slurp/
COMMENT=		Read/write/append files quickly

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/File/Slurp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
