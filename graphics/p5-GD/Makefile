# $NetBSD: Makefile,v 1.56 2013/01/26 21:37:56 adam Exp $

DISTNAME=	GD-2.46
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
SVR4_PKGNAME=	p5bd
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/GD/
COMMENT=	Perl5 interface to gd graphics library
LICENSE=	gnu-gpl-v2 OR artistic-2.0

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILDLINK_API_DEPENDS.gd+=	gd>=2.0.28

REPLACE_PERL=	qd.pl

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/GD/.packlist
PERL5_OPTIONS+=		threads

MAKE_ENV+=		GD_LIBS=${LDFLAGS:Q}
#MAKE_PARAMS+=		--lib_gd_path=${BUILDLINK_PREFIX.gd}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
