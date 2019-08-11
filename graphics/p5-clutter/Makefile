# $NetBSD: Makefile,v 1.41 2019/08/11 13:21:16 wiz Exp $
#

DISTNAME=	Clutter-1.110
PKGNAME=	p5-${DISTNAME:tl}
PKGREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Clutter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.clutter-project.org/
COMMENT=	Perl interface to the 1.x series of the Clutter toolkit
LICENSE=	gnu-lgpl-v2.1

#BUILD_DEPENDS+=	{perl>=5.8.8,p5-ExtUtils-MakeMaker>=6.30}:../../devel/p5-ExtUtils-MakeMaker
DEPENDS+=	p5-glib2>=1.253:../../devel/p5-glib2
DEPENDS+=	p5-cairo-gobject>=1.000:../../graphics/p5-cairo-gobject
DEPENDS+=	p5-Glib-Object-Introspection>=0.002:../../devel/p5-Glib-Object-Introspection
DEPENDS+=	p5-pango>=1.220:../../devel/p5-pango
DEPENDS+=	clutter>=1.0:../../graphics/clutter

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	# empty

PERL5_PACKLIST=	auto/Clutter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
