# $NetBSD: Makefile,v 1.1.1.1 2004/09/26 04:41:09 epg Exp $

DISTNAME=	PerlIO-via-symlink-0.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=OurNet/CLKAO/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	PerlIO layers to create symlinks

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/PerlIO/via/symlink/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
