# $NetBSD: Makefile,v 1.5 2003/11/12 01:31:47 salo Exp $
#

.include "../../devel/GConf2/Makefile.common"

PKGNAME=	${DISTNAME:S/GConf/GConf2-ui/}
PKGREVISION=	3

CONFIGURE_ENV+=	PKG_USE_GTK=yes

do-build:
	@cd ${WRKSRC}/gconf && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} \
		-f Makefile gconf-sanity-check-2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gconf/.libs/gconf-sanity-check-2 \
		${PREFIX}/libexec

.include "../../devel/GConf2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
