# $NetBSD: Makefile,v 1.16 2008/11/16 23:40:36 he Exp $
#

DISTNAME=	ExtUtils-PkgConfig-1.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gtk2-perl.sourceforge.net/
COMMENT=	Simplistic perl interface to pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/ExtUtils/PkgConfig/.packlist
USE_LANGUAGES=	# empty
USE_TOOLS+=	pkg-config:run

TOOLS_CMD.pkg-config= ${PREFIX}/bin/pkg-config

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
