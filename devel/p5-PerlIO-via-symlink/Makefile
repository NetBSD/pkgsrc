# $NetBSD: Makefile,v 1.13 2012/10/31 11:18:50 asau Exp $

DISTNAME=	PerlIO-via-symlink-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=OurNet/CLKAO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	PerlIO layers to create symlinks

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/PerlIO/via/symlink/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
