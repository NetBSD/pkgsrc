# $NetBSD: Makefile,v 1.13 2003/04/26 09:49:36 jmmv Exp $
#

DISTNAME=	WSoundServer-0.4.0
PKGNAME=	wsoundserver-0.4.0
PKGREVISION=	1
CATEGORIES=	audio wm windowmaker
MASTER_SITES=	ftp://shadowmere.student.utwente.nl/pub/WindowMaker/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://shadowmere.student.utwente.nl/
COMMENT=	sound server for windowmaker

USE_BUILDLINK2=		YES

USE_X11BASE=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

post-patch:
	@cd ${WRKSRC}/doc && for f in *; do				\
		${SED} "s/1x/1/g" $$f > $$f.tmp && ${MV} $$f.tmp $$f;	\
	done &&								\
	for f in get-wsound-flags.1x getsoundset.1x setsoundset.1x	\
		wsoundplay.1x wsoundserver.1x; do			\
		g=`${ECHO} $$f | ${SED} "s/x$$//"`;			\
		${MV} $$f $$g;						\
	done
	${SED} -e "s|@PREFIX@|${PREFIX}|g"				\
		${FILESDIR}/WMSound > ${WRKSRC}/WMSound

post-install:
	${INSTALL_DATA} ${WRKSRC}/WMSound ${PREFIX}/etc/WindowMaker

.include "../../audio/libaudiofile/buildlink2.mk"
.include "../../devel/libdockapp/buildlink2.mk"
.include "../../devel/libproplist/buildlink2.mk"
.include "../../wm/windowmaker/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
