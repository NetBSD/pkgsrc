# $NetBSD: Makefile,v 1.3 2007/09/20 21:12:57 wiz Exp $

DISTNAME=		GTop-0.16
PKGNAME=		p5-GTop-0.16
PKGREVISION=		1
CATEGORIES=		sysutils perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=GTop/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/GTop/
COMMENT=		Perl interface to libgtop

USE_TOOLS+=		pkg-config

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/GTop/.packlist

.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
