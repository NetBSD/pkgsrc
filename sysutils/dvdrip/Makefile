# $NetBSD: Makefile,v 1.1.1.1 2003/06/23 07:36:15 mrg Exp $
#

VERS=		0.50.13
DISTNAME=	Video-DVDRip-${VERS}
PKGNAME=	dvdrip-${VERS}
CATEGORIES=	x11 sysutils
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Video/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.exit1.org/dvdrip/
COMMENT=	Graphical frontend for DVD ripping

DEPENDS+=	cdrdao>=1.1.7:../../sysutils/cdrdao
DEPENDS+=	transcode>=0.6.2:../../graphics/transcode
DEPENDS+=	mplayer>=0.90:../../graphics/mplayer
DEPENDS+=	ogmtools-[0-9]*:../../graphics/ogmtools
DEPENDS+=	vcdimager>=0.7.12:../../sysutils/vcdimager-devel
DEPENDS+=	cdrecord>=1.10:../../sysutils/cdrecord
DEPENDS+=	subtitleripper-[0-9]*:../../textproc/subtitleripper
.if (${MACHINE_ARCH} == "i386")
DEPENDS+=	rar>=2.02:../../archivers/rar
.endif

BUILDLINK_DEPENDS.perl= perl>=5.6.0

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES

# XXX xine support
# XXX fping support
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/ImageMagick/buildlink2.mk"
.include "../../graphics/mjpegtools/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
