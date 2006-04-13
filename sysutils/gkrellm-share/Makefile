# $NetBSD: Makefile,v 1.5 2006/04/13 19:14:45 cube Exp $
.include "../../sysutils/gkrellm/Makefile.common"

PKGREVISION=		#
GKRELLM_PKGBASE=	gkrellm-share

COMMENT=		GKrellM2 locale files

USE_TOOLS+=		msgfmt

MAKE_ENV+=		MODULES=po

INSTALLATION_DIRS=	share/gkrellm2

post-install:
	${INSTALL_DATA} ${GKRELLM_SRCDIR}/README ${GKRELLM_SRCDIR}/COPYRIGHT ${PREFIX}/share/gkrellm2

.include "../../mk/bsd.pkg.mk"
