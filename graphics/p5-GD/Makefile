# $NetBSD: Makefile,v 1.40 2009/04/12 00:32:42 sno Exp $

DISTNAME=	GD-2.41
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5bd
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/GD/GD.html
COMMENT=	Perl5 interface to gd graphics library

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILDLINK_API_DEPENDS.gd+=	gd>=2.0.28

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/GD/.packlist
PERL5_OPTIONS+=		threads

MAKE_ENV+=		GD_LIBS=${LDFLAGS:Q}
MAKE_PARAMS+=		-lib_gd_path=${BUILDLINK_PREFIX.gd}

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
