# $NetBSD: Makefile,v 1.7 2003/12/14 19:45:45 jmmv Exp $
#

.include "../../devel/GConf2/Makefile.common"

PKGNAME=	${DISTNAME:S/GConf/GConf2-ui/}

CONFIGURE_ENV+=	PKG_USE_GTK=yes

BUILD_DIRS=	${WRKSRC}/gconf
BUILD_TARGETS=	GConfX.h gconf-sanity-check-2

#do-build:
#	@cd ${WRKSRC}/gconf && \
#		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} \
#		-f Makefile GConfX.h gconf-sanity-check-2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gconf/.libs/gconf-sanity-check-2 \
		${PREFIX}/libexec

.include "../../devel/GConf2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
