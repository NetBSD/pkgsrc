# $NetBSD: Makefile,v 1.1.1.1 2001/03/12 21:10:25 wiz Exp $
#

DISTNAME=	WSoundServer-0.4.0
PKGNAME=	wsoundserver-0.4.0
CATEGORIES=	audio wm
MASTER_SITES=	ftp://shadowmere.student.utwente.nl/pub/WindowMaker/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://shadowmere.student.utwente.nl/
COMMENT=	sound server for windowmaker

DEPENDS+=	libaudiofile>=0.2.1:../../audio/libaudiofile
DEPENDS+=	libdockapp>=0.4:../../devel/libdockapp
DEPENDS+=	libproplist>=0.10.1:../../devel/libproplist
DEPENDS+=	windowmaker>=0.64.0:../../wm/windowmaker

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_X11BASE=		YES

CONFIGURE_ARGS+=	--with-incs-from=-I${LOCALBASE}/include

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

.include "../../mk/bsd.pkg.mk"
