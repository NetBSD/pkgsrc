# $NetBSD: Makefile,v 1.66 2020/03/20 11:57:30 nia Exp $

DISTNAME=	Glib-1.329
PKGNAME=	p5-${DISTNAME:S/Glib/glib2/}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk2-perl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gtk2-perl.sourceforge.net/
#HOMEPAGE=	http://search.cpan.org/dist/Glib/
COMMENT=	Perl bindings for Glib 2
LICENSE=	gnu-lgpl-v2.1

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
