# $NetBSD: Makefile,v 1.12 2012/09/15 10:06:31 obache Exp $

DISTNAME=		GTop-0.18
PKGNAME=		p5-GTop-0.16
PKGREVISION=		1
CATEGORIES=		sysutils perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=GTop/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/GTop/
COMMENT=		Perl interface to libgtop

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir
LICENSE=		${PERL5_LICENSE}

USE_TOOLS+=		pkg-config

PERL5_PACKLIST=		auto/GTop/.packlist

.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
