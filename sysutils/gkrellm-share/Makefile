# $NetBSD: Makefile,v 1.7 2012/10/23 19:51:03 asau Exp $
.include "../../sysutils/gkrellm/Makefile.common"

PKGREVISION=		#
GKRELLM_PKGBASE=	gkrellm-share

COMMENT=		GKrellM2 locale files

USE_TOOLS+=		msgfmt
USE_PKGLOCALEDIR=	yes

MAKE_ENV+=		MODULES=po
INSTALL_MAKE_FLAGS=	LOCALEDIR=${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale

INSTALLATION_DIRS=	share/gkrellm2 ${PKGLOCALEDIR}/locale

post-install:
	${INSTALL_DATA} ${GKRELLM_SRCDIR}/README ${GKRELLM_SRCDIR}/COPYRIGHT ${DESTDIR}${PREFIX}/share/gkrellm2

.include "../../mk/bsd.pkg.mk"
