# $NetBSD: Makefile,v 1.3 2005/04/11 21:45:34 tv Exp $

DISTNAME=	PerlIO-via-symlink-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=OurNet/CLKAO/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	PerlIO layers to create symlinks

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/PerlIO/via/symlink/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
