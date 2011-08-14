# $NetBSD: Makefile,v 1.12 2011/08/14 12:26:08 obache Exp $

DISTNAME=	Gtk2-GladeXML-1.007
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	x11 perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk2-perl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gtk2-perl.sourceforge.net/
COMMENT=	Perl bindings for Glade (2)

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

DEPENDS+=	p5-ExtUtils-Depends>=0.300:../../devel/p5-ExtUtils-Depends
DEPENDS+=	p5-ExtUtils-PkgConfig>=1.03:../../devel/p5-ExtUtils-PkgConfig

USE_TOOLS+=	pkg-config

PERL5_PACKLIST=	auto/Gtk2/GladeXML/.packlist

.include "../../devel/p5-glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../x11/p5-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
