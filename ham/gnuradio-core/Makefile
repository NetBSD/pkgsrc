# $NetBSD: Makefile,v 1.124 2024/05/29 16:33:05 adam Exp $

PKGNAME=	gnuradio-core-${VERSION}
PKGREVISION=	3
COMMENT=	Core part of GNU Radio, all others need this

PLIST_MINUS=	# empty
.include	"Makefile.common"

#CONF_FILES+=	${EGDIR}/gnuradio-runtime.conf	${PKG_SYSCONFDIR}/gnuradio-runtime.conf
#CONF_FILES+=	${EGDIR}/gr-audio-jack.conf	${PKG_SYSCONFDIR}/gr-audio-jack.conf
#CONF_FILES+=	${EGDIR}/gr-audio-portaudio.conf ${PKG_SYSCONFDIR}/gr-audio-portaudio.conf
#CONF_FILES+=	${EGDIR}/gr-audio.conf		${PKG_SYSCONFDIR}/gr-audio.conf

.include "../../mk/oss.buildlink3.mk"
.if ${OSS_TYPE} != "none"
#CONF_FILES+=	${EGDIR}/gr-audio-oss.conf	${PKG_SYSCONFDIR}/gr-audio-oss.conf
PLIST_SRC=	${PKGDIR}/PLIST ${PKGDIR}/PLIST.oss
.endif

# set default as minimum
CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF

# Take care CONF_FILES stuff (The same code in Nocore.mk)
#post-install:
#	${MV} ${DESTDIR}${PREFIX}/etc/gnuradio/conf.d/* \
#	      ${DESTDIR}${PREFIX}/${EGDIR}/

.include "../../mk/bsd.pkg.mk"
