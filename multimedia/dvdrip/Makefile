# $NetBSD: Makefile,v 1.4 2004/04/06 04:10:48 xtraeme Exp $
#

VERS=		0.50.16
DISTNAME=	Video-DVDRip-${VERS}
PKGNAME=	dvdrip-${VERS}
PKGREVISION=	2
CATEGORIES=	multimedia x11 sysutils
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Video/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.exit1.org/dvdrip/
COMMENT=	Graphical frontend for DVD ripping

DEPENDS+=	cdrdao>=1.1.7:../../sysutils/cdrdao
DEPENDS+=	transcode>=0.6.9:../../graphics/transcode
DEPENDS+=	mplayer>=0.90:../../multimedia/mplayer
DEPENDS+=	ogmtools-[0-9]*:../../graphics/ogmtools
DEPENDS+=	vcdimager>=0.7.12:../../sysutils/vcdimager-devel
DEPENDS+=	cdrecord>=1.10:../../sysutils/cdrecord
DEPENDS+=	subtitleripper-[0-9]*:../../textproc/subtitleripper
DEPENDS+=	p5-Gdk-Pixbuf-[0-9]*:../../graphics/p5-Gdk-Pixbuf

.if (${MACHINE_ARCH} == "i386")
#DEPENDS+=	rar>=2.02:../../archivers/rar
.endif

BUILDLINK_DEPENDS.perl= perl>=5.6.0

USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES

PERL5_PACKLIST= ${PERL5_SITEARCH}/auto/Video/DVDRip/.packlist

# XXX xine support
# XXX fping support
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../multimedia/mjpegtools/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
