# $NetBSD: Makefile,v 1.5 2021/05/09 09:12:08 nia Exp $

.include "Makefile.common"

PKGNAME=	ossinfo-${OSS_CMD_VER}
PKGREVISION=	1
CATEGORIES=	audio

MAINTAINER=	nia@NetBSD.org
COMMENT=	Command line program to display OSSv4 device information

SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Correcting the path to the OSS device.
SUBST_FILES.oss+=	cmd/ossinfo/ossinfo.c
SUBST_SED.oss+=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"

.include "../../mk/bsd.pkg.mk"
