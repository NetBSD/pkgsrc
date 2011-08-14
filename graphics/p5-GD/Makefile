# $NetBSD: Makefile,v 1.50 2011/08/14 12:59:48 obache Exp $

DISTNAME=	GD-2.46
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5bd
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/GD/
COMMENT=	Perl5 interface to gd graphics library
LICENSE=	gnu-gpl-v2 OR artistic-2.0

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILDLINK_API_DEPENDS.gd+=	gd>=2.0.28

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/GD/.packlist
PERL5_OPTIONS+=		threads

MAKE_ENV+=		GD_LIBS=${LDFLAGS:Q}
#MAKE_PARAMS+=		--lib_gd_path=${BUILDLINK_PREFIX.gd}

.include "../../graphics/gd/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
