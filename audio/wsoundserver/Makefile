# $NetBSD: Makefile,v 1.70 2023/11/14 14:01:27 wiz Exp $
#

DISTNAME=	WSoundServer-0.4.0
PKGNAME=	wsoundserver-0.4.0
PKGREVISION=	33
CATEGORIES=	audio wm windowmaker
MASTER_SITES=	# ftp://shadowmere.student.utwente.nl/pub/WindowMaker/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://shadowmere.student.utwente.nl/
COMMENT=	Sound server for windowmaker
LICENSE=	modified-bsd

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		pkg-config

.include "../../mk/oss.buildlink3.mk"

LIBS+=			${LIBOSSAUDIO}

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}	# not really needed
CONFIGURE_ENV+=		ac_cv_path_AUDIOFILE_CONFIG="pkg-config audiofile"
CONFIGURE_ENV+=		TOOLS_PATH_SH=${TOOLS_PATH.sh}
PKG_SYSCONFSUBDIR=	WindowMaker
EGDIR=			${PREFIX}/share/examples/wsoundserver
CONF_FILES=		${EGDIR:Q}/WMSound ${PKG_SYSCONFDIR:Q}/WMSound

SUBST_CLASSES+=		1x
SUBST_STAGE.1x=		pre-configure
SUBST_MESSAGE.1x=	Changing the man page category from 1x to 1.
SUBST_FILES.1x=		doc/*
SUBST_SED.1x=		-e s,1x,1,g

INSTALLATION_DIRS+=	${EGDIR}

post-patch:
	set -e;								\
	cd ${WRKSRC:Q}/doc;						\
	for f in get-wsound-flags getsoundset setsoundset wsoundplay	\
		wsoundserver; do					\
		g=`${ECHO} $$f | ${SED} "s/x$$//"`;			\
		${MV} "$$f".1x "$$f".1;					\
	done
	${SED} -e "s|@PREFIX@|${PREFIX}|g"				\
		${FILESDIR:Q}/WMSound > ${WRKSRC:Q}/WMSound

post-install:
	${INSTALL_DATA} ${WRKSRC:Q}/WMSound ${DESTDIR}${EGDIR}

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../devel/libdockapp/buildlink3.mk"
.include "../../devel/libproplist/buildlink3.mk"
.include "../../wm/windowmaker/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
