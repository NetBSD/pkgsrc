# $NetBSD: Makefile,v 1.4 2001/07/07 17:17:58 tron Exp $
#

DISTNAME=	WSoundServer-0.4.0
PKGNAME=	wsoundserver-0.4.0
CATEGORIES=	audio wm
MASTER_SITES=	ftp://shadowmere.student.utwente.nl/pub/WindowMaker/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://shadowmere.student.utwente.nl/
COMMENT=	sound server for windowmaker

DEPENDS+=	windowmaker>=0.64.0:../../wm/windowmaker

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_X11BASE=		YES

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == SunOS)
CPPFLAGS+=	-I${X11BASE}/include
MAKE_ENV+=	OSSAUDIO_LIBS=
.else
MAKE_ENV+=	OSSAUDIO_LIBS=-lossaudio
.endif

post-patch:
	@cd ${WRKSRC}/doc && for f in *; do				\
		${SED} "s/1x/1/g" $$f > $$f.tmp && ${MV} $$f.tmp $$f;	\
	done &&								\
	for f in get-wsound-flags.1x getsoundset.1x setsoundset.1x	\
		wsoundplay.1x wsoundserver.1x; do			\
		g=`${ECHO} $$f | ${SED} "s/x$$//"`;			\
		${MV} $$f $$g;						\
	done
	${SED} "s|@PREFIX@|${PREFIX}|" ${FILESDIR}/WMSound > ${WRKSRC}/WMSound

post-install:
	${INSTALL_DATA} ${WRKSRC}/WMSound ${PREFIX}/etc/WindowMaker

.include "../../audio/libaudiofile/buildlink.mk"
.include "../../devel/libdockapp/buildlink.mk"
.include "../../devel/libproplist/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
