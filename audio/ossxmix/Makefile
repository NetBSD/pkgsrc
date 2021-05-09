# $NetBSD: Makefile,v 1.2 2021/05/09 08:38:20 nia Exp $

.include "../../audio/ossinfo/Makefile.common"

PKGNAME=	ossxmix-${DISTNAME:S/oss-v//1:S/-src-bsd//1:S/-/./g}
CATEGORIES=	audio

MAINTAINER=	nia@NetBSD.org
COMMENT=	Audio mixer GUI from OSSv4

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS+=	share/applications

install-desktop-file: .PHONY
	${INSTALL_DATA} ${FILESDIR}/ossxmix.desktop \
		${DESTDIR}${PREFIX}/share/applications

do-install: install-desktop-file

.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
