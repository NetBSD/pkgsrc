# $NetBSD: Makefile,v 1.1 2014/10/13 12:51:08 mef Exp $

PKGNAME=	gnuradio-default-${VERSION}
COMMENT=	Full package of gnuradio (conflict to meta-pkgs)
INSTALLATION_DIRS+= ${EGDIR}

# The half of the same target in Nocore.mk
post-install:
# Take care CONF_FILES stuff
	${MV}               ${DESTDIR}${PREFIX}/etc/gnuradio/conf.d/* \
	                    ${DESTDIR}${PREFIX}/${EGDIR}/

.include	"../../ham/gnuradio-core/Makefile.common"
CMAKE_ARGS+=	-DZEROMQ_INCLUDE_DIRS=${PREFIX}/include

CONFLICTS=	gnuradio-[0-9]*
CONFLICTS+=	gnuradio-atsc-[0-9]*
CONFLICTS+=	gnuradio-channels-[0-9]*
CONFLICTS+=	gnuradio-companion-[0-9]*
CONFLICTS+=	gnuradio-core-[0-9]*

CONFLICTS+=	gnuradio-ctrlport-[0-9]*
CONFLICTS+=	gnuradio-digital-[0-9]*
CONFLICTS+=	gnuradio-doxygen-[0-9]*
CONFLICTS+=	gnuradio-dtv-[0-9]*
CONFLICTS+=	gnuradio-fcd-[0-9]*

CONFLICTS+=	gnuradio-fec-[0-9]*
CONFLICTS+=	gnuradio-noaa-[0-9]*
CONFLICTS+=	gnuradio-pager-[0-9]*
CONFLICTS+=	gnuradio-qtgui-[0-9]*
CONFLICTS+=	gnuradio-trellis-[0-9]*

CONFLICTS+=	gnuradio-uhd-[0-9]*
CONFLICTS+=	gnuradio-utils-[0-9]*
CONFLICTS+=	gnuradio-video-sdl-[0-9]*
CONFLICTS+=	gnuradio-vocoder-[0-9]*
CONFLICTS+=	gnuradio-wavelet-[0-9]*

CONFLICTS+=	gnuradio-wxgui-[0-9]*
CONFLICTS+=	gnuradio-zeromq-[0-9]*

CONF_FILES+=	${EGDIR}/gr-qtgui.conf		${PKG_SYSCONFDIR}/gr-qtgui.conf
CONF_FILES+=	${EGDIR}/modtool.conf		${PKG_SYSCONFDIR}/modtool.conf
CONF_FILES+=	${EGDIR}/gr-wxgui.conf		${PKG_SYSCONFDIR}/gr-wxgui.conf
CONF_FILES+=	${EGDIR}/gnuradio-runtime.conf	${PKG_SYSCONFDIR}/gnuradio-runtime.conf

BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml/
DEPENDS+=	${PYPKGPREFIX}-qwt-qt4-[0-9]*:../../x11/py-qwt-qt4

# --------	 R E S E T    H E R E  -------------
CMAKE_ARGS+=	-DENABLE_DEFAULT=True

post-patch:
	${CP}  ${PKGDIR}/../gnuradio-zeromq/files/zmq.hpp ${WRKSRC}/gr-zeromq/include/

.include	"../../devel/SDL/buildlink3.mk"
.include	"../../devel/cppunit/buildlink3.mk"
.include	"../../devel/libusb1/buildlink3.mk"
.include	"../../devel/orc/buildlink3.mk"

.include	"../../ham/uhd/buildlink3.mk"
.include	"../../math/gsl/buildlink3.mk"
# gr-zeromq/lib/pub_sink_impl.h:27:19: fatal error: zmq.hpp: No such file..
.include	"../../net/zeromq/buildlink3.mk"

.include	"../../x11/py-gtk2/buildlink3.mk"
.include	"../../x11/py-qt4/buildlink3.mk"
.include	"../../x11/py-wxWidgets/buildlink3.mk"
.include	"../../x11/qt4-libs/buildlink3.mk"
.include	"../../x11/qwt-qt4/buildlink3.mk"
.include	"../../x11/wxGTK28/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"
