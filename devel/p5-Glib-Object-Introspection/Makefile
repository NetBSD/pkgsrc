# $NetBSD: Makefile,v 1.3 2014/05/05 00:47:46 ryoon Exp $

DISTNAME=	Glib-Object-Introspection-0.019
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk2-perl/} \
		${MASTER_SITE_PERL_CPAN:=Glib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gtk2-perl.sourceforge.net/
COMMENT=	Dynamically create Perl language bindings
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	p5-ExtUtils-Depends>=0.300:../../devel/p5-ExtUtils-Depends
DEPENDS+=	p5-ExtUtils-PkgConfig>=1.000:../../devel/p5-ExtUtils-PkgConfig

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c
USE_TOOLS+=		pkg-config

PERL5_PACKLIST=		auto/Glib/Object/Introspection/.packlist

.include "../../mk/bsd.prefs.mk"
.if !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
BUILDLINK_DEPMETHOD.cairo-gobject=	build
.include "../../graphics/cairo-gobject/buildlink3.mk"
.endif

BUILDLINK_API_DEPENDS.p5-glib2+=	p5-glib2>=1.280
.include "../../devel/p5-glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=0.10.0
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
