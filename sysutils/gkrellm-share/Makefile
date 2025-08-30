# $NetBSD: Makefile,v 1.8 2025/08/30 08:24:21 pho Exp $

.include "../../sysutils/gkrellm/Makefile.common"

GKRELLM_PKGBASE=	gkrellm-share

COMMENT=		GKrellM2 locale files

BUILD_DIRS=		po
INSTALLATION_DIRS=	share/gkrellm2

.if !empty(PKG_OPTIONS:Mnls)
USE_TOOLS+=		msgfmt
USE_PKGLOCALEDIR=	yes
INSTALL_MAKE_FLAGS=	LOCALEDIR=${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale
INSTALLATION_DIRS+=	${PKGLOCALEDIR}/locale
PLIST.nls=		yes
.endif
PLIST_VARS+=		nls
PRINT_PLIST_AWK+=	/^${PKGLOCALEDIR:S,/,\/,g}\/locale/ { $$0 = "$${PLIST.nls}" $$0 }

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/COPYRIGHT ${DESTDIR}${PREFIX}/share/gkrellm2

.include "../../mk/bsd.pkg.mk"
