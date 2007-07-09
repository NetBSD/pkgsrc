# $NetBSD: Makefile,v 1.1.1.1.4.1 2007/07/09 14:24:04 ghen Exp $

DISTNAME=		GTop-0.16
PKGNAME=		p5-GTop-0.16
CATEGORIES=		sysutils perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=GTop/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/GTop/
COMMENT=		Perl interface to libgtop

USE_TOOLS+=		pkg-config

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/GTop/.packlist

.include "../../sysutils/libgtop2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
