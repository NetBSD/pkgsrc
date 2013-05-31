# $NetBSD: Makefile,v 1.46 2013/05/31 12:40:55 wiz Exp $

DISTNAME=	Glib-1.262
PKGNAME=	p5-${DISTNAME:S/Glib/glib2/}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk2-perl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gtk2-perl.sourceforge.net/
#HOMEPAGE=	http://search.cpan.org/dist/Glib/
COMMENT=	Perl bindings for Glib 2
LICENSE=	gnu-lgpl-v2.1

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-ExtUtils-Depends>=0.300:../../devel/p5-ExtUtils-Depends
DEPENDS+=	p5-ExtUtils-PkgConfig>=1.00:../../devel/p5-ExtUtils-PkgConfig

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.12.0

# "Can't locate Glib/ParseXSDoc.pm in @INC .."
MAKE_JOBS_SAFE=	no

USE_TOOLS+=		pkg-config
PERL5_PACKLIST=		auto/Glib/.packlist

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
