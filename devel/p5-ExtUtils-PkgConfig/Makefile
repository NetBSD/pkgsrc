# $NetBSD: Makefile,v 1.20 2012/07/06 10:26:46 sno Exp $

DISTNAME=	ExtUtils-PkgConfig-1.13
PKGNAME=	p5-${DISTNAME}
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

TOOLS_CMD.pkg-config=	${TOOLS_PATH.pkg-config}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
