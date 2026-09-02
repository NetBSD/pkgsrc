# $NetBSD: Makefile,v 1.83 2026/09/02 19:03:26 wiz Exp $
#

DISTNAME=	gkrellflynn-0.9
PKGNAME=	${DISTNAME:S/gkrell/gkrellm-/}
PKGREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	http://bax.comlab.uni-rostock.de/fileadmin/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bax.comlab.uni-rostock.de/en/projects/flynn/
COMMENT=	GKrellM2 plugin that shows system load with a DooM marine
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

MAKE_FILE=	${FILESDIR}/Makefile
MAKE_FLAGS+=	INSTALL_LIB_DIR=${INSTALL_LIB_DIR:Q}
MAKE_FLAGS+=	INSTALL_LIB=${INSTALL_LIB:Q}
MAKE_FLAGS+=	PLUGIN_DIR=${PREFIX:Q}/lib/gkrellm2/plugins

.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
