# $NetBSD: Makefile,v 1.18 2011/08/12 18:47:30 adam Exp $

DISTNAME=	ExtUtils-PkgConfig-1.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gtk2-perl.sourceforge.net/
COMMENT=	Simplistic perl interface to pkg-config
LICENSE=	gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
USE_TOOLS+=		pkg-config:run
PERL5_PACKLIST=		auto/ExtUtils/PkgConfig/.packlist

TOOLS_CMD.pkg-config=	${PREFIX}/bin/pkg-config

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
