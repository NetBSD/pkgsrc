# $NetBSD: Makefile,v 1.11 2011/08/14 12:26:31 obache Exp $

DISTNAME=	PerlIO-via-symlink-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=OurNet/CLKAO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	PerlIO layers to create symlinks

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/PerlIO/via/symlink/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
