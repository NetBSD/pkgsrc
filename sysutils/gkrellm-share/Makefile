# $NetBSD: Makefile,v 1.4 2006/04/13 18:23:37 jlam Exp $
.include "../../sysutils/gkrellm/Makefile.common"

PKGREVISION=		1
GKRELLM_PKGBASE=	gkrellm-share

COMMENT=		GKrellM2 locale files

USE_TOOLS+=		msgfmt

MAKE_ENV+=		MODULES=po

INSTALLATION_DIRS=	share/gkrellm2

post-install:
	${INSTALL_DATA} ${GKRELLM_SRCDIR}/README ${GKRELLM_SRCDIR}/COPYRIGHT ${PREFIX}/share/gkrellm2

.include "../../mk/bsd.pkg.mk"
