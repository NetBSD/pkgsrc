# $NetBSD: Makefile,v 1.16 2014/05/29 23:37:30 wiz Exp $

DISTNAME=		GTop-0.18
PKGNAME=		p5-GTop-0.16
PKGREVISION=		4
CATEGORIES=		sysutils perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=GTop/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/GTop/
COMMENT=		Perl interface to libgtop

PKG_INSTALLATION_TYPES=	overwrite pkgviews

LICENSE=		${PERL5_LICENSE}

USE_TOOLS+=		pkg-config

PERL5_PACKLIST=		auto/GTop/.packlist

.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
