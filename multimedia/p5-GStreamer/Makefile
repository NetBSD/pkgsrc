# $NetBSD: Makefile,v 1.33 2022/06/28 11:34:56 wiz Exp $

DISTNAME=	GStreamer-0.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	multimedia perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GStreamer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/GStreamer
COMMENT=	Perl interface to the GStreamer library
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	p5-ExtUtils-Depends>=0.205:../../devel/p5-ExtUtils-Depends
DEPENDS+=	p5-ExtUtils-PkgConfig>=1.07:../../devel/p5-ExtUtils-PkgConfig

MAKE_JOBS_SAFE=	no

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c

PERL5_PACKLIST=	auto/GStreamer/.packlist

BUILDLINK_API_DEPENDS.p5-glib2+=	p5-glib2>=1.180
.include "../../devel/p5-glib2/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
