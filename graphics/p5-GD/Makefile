# $NetBSD: Makefile,v 1.27 2004/12/26 23:42:09 jlam Exp $

DISTNAME=	GD-2.19
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5bd
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/GD/GD.html
COMMENT=	Perl5 interface to gd graphics library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILDLINK_DEPENDS.gd+=	gd>=2.0.28

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/GD/.packlist
PERL5_OPTIONS+=		threads

MAKE_ENV+=		GD_LIBS="${LDFLAGS}"
MAKE_PARAMS+=		-lib_gd_path=${BUILDLINK_PREFIX.gd}

.include "../../graphics/gd/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
