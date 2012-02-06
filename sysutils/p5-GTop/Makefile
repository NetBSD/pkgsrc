# $NetBSD: Makefile,v 1.9 2012/02/06 12:41:38 wiz Exp $

DISTNAME=		GTop-0.16
PKGNAME=		p5-GTop-0.16
PKGREVISION=		6
CATEGORIES=		sysutils perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=GTop/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/GTop/
COMMENT=		Perl interface to libgtop

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config

PERL5_PACKLIST=		auto/GTop/.packlist

.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
