# $NetBSD: Makefile,v 1.1.1.1 2004/02/24 22:27:27 cube Exp $
.include "../../sysutils/gkrellm/Makefile.common"

GKRELLM_PKGBASE=	gkrellm-share

COMMENT=		GKrellM2 locale files

BUILD_USES_MSGFMT=	YES

MAKE_ENV+=		MODULES=po

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/gkrellm2
	${INSTALL_DATA} ${GKRELLM_SRCDIR}/README ${GKRELLM_SRCDIR}/COPYRIGHT ${PREFIX}/share/gkrellm2

.include "../../mk/bsd.pkg.mk"
