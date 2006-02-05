# $NetBSD: Makefile,v 1.3 2006/02/05 23:10:50 joerg Exp $
.include "../../sysutils/gkrellm/Makefile.common"

PKGREVISION=		1
GKRELLM_PKGBASE=	gkrellm-share

COMMENT=		GKrellM2 locale files

BUILD_USES_MSGFMT=	YES

MAKE_ENV+=		MODULES=po

INSTALLATION_DIRS=	share/gkrellm2

post-install:
	${INSTALL_DATA} ${GKRELLM_SRCDIR}/README ${GKRELLM_SRCDIR}/COPYRIGHT ${PREFIX}/share/gkrellm2

.include "../../mk/bsd.pkg.mk"
