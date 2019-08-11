# $NetBSD: Makefile,v 1.33 2019/08/11 13:19:24 wiz Exp $

DISTNAME=	ExtUtils-PkgConfig-1.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gtk2-perl.sourceforge.net/
COMMENT=	Simplistic perl interface to pkg-config
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=		# empty
USE_TOOLS+=		pkg-config:run
PERL5_PACKLIST=		auto/ExtUtils/PkgConfig/.packlist

TOOLS_CMD.pkg-config=	${TOOLS_PATH.pkg-config}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
