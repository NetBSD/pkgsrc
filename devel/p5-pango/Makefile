# $NetBSD: Makefile,v 1.40 2018/08/22 09:44:57 wiz Exp $
#

DISTNAME=	Pango-1.227
PKGNAME=	p5-${DISTNAME:tl}
PKGREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/X/XA/XAOC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~xaoc/Pango/
COMMENT=	Perl bindings to the pango library
LICENSE=	gnu-lgpl-v2.1

MAKE_JOBS_SAFE=	no

USE_TOOLS+=	pkg-config

BUILDLINK_API_DEPENDS.p5-glib2+=	p5-glib2>=1.220
BUILDLINK_API_DEPENDS.p5-cairo+=	p5-cairo>=1.000
BUILDLINK_API_DEPENDS.pango+=		pango>=1.0.0

DEPENDS+=	p5-ExtUtils-Depends>=0.300:../../devel/p5-ExtUtils-Depends
DEPENDS+=	p5-ExtUtils-PkgConfig>=1.03:../../devel/p5-ExtUtils-PkgConfig

PERL5_PACKLIST=	auto/Pango/.packlist

.include "../../devel/p5-glib2/buildlink3.mk"
.include "../../graphics/p5-cairo/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
