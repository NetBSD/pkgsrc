# $NetBSD: Makefile,v 1.1 2021/05/09 09:06:58 nia Exp $

.include "../../audio/ossinfo/Makefile.common"

PKGNAME=	ossplay-${DISTNAME:S/oss-v//1:S/-src-bsd//1:S/-/./g}
CATEGORIES=	audio

MAINTAINER=	nia@NetBSD.org
COMMENT=	Command line programs for playing/recording from OSSv4 devices

SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Correcting the path to the OSS device.
SUBST_FILES.oss+=	cmd/ossplay/ossplay.c
SUBST_SED.oss+=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"

install-ossrecord: .PHONY
	cd ${DESTDIR}${PREFIX}/bin && ${LN} -sf ossplay ossrecord
	${INSTALL_DATA} ${WRKSRC}/cmd/ossrecord/ossrecord.man \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

do-install: install-ossrecord

.include "../../mk/bsd.pkg.mk"
