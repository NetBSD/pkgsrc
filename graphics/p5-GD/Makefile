# $NetBSD: Makefile,v 1.19 2004/04/25 03:35:25 minskim Exp $

DISTNAME=	GD-2.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5bd
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/GD/GD.html
COMMENT=	Perl5 interface to gd graphics library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_X11=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/GD/.packlist

MAKE_ENV+=		GD_LIBS="${LDFLAGS}"
MAKE_PARAMS+=		-lib_gd_path=${PREFIX}

.include "../../graphics/gd/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
