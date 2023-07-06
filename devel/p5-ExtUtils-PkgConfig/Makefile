# $NetBSD: Makefile,v 1.40 2023/07/06 09:39:08 wiz Exp $

DISTNAME=	ExtUtils-PkgConfig-1.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gtk2-perl.sourceforge.net/
COMMENT=	Simplistic perl interface to pkg-config
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=		# empty
USE_TOOLS+=		pkg-config:run
PERL5_PACKLIST=		auto/ExtUtils/PkgConfig/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
