# $NetBSD: Makefile,v 1.2 2005/09/08 13:19:56 cube Exp $
.include "../../sysutils/gkrellm/Makefile.common"

GKRELLM_PKGBASE=	gkrellm-share

COMMENT=		GKrellM2 locale files

BUILD_USES_MSGFMT=	YES

MAKE_ENV+=		MODULES=po

INSTALLATION_DIRS=	share/gkrellm2

post-install:
	${INSTALL_DATA} ${GKRELLM_SRCDIR}/README ${GKRELLM_SRCDIR}/COPYRIGHT ${PREFIX}/share/gkrellm2

.include "../../mk/bsd.pkg.mk"
