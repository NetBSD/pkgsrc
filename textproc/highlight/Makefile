#	$NetBSD: Makefile,v 1.7 2014/08/09 17:15:59 schmonz Exp $

DISTNAME=		highlight-3.18
CATEGORIES=		textproc
MASTER_SITES=		http://www.andre-simon.de/zip/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.andre-simon.de/
COMMENT=		Converts source code to formatted text with syntax highlighting
LICENSE=		gnu-gpl-v3

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
MANCOMPRESSED=		yes

MAKE_FILE=		makefile
BUILD_TARGET=		cli

PKG_SYSCONFSUBDIR=	highlight

EGDIR=			${PREFIX}/share/examples/highlight
CONF_FILES=		${EGDIR}/filetypes.conf			\
			${PKG_SYSCONFDIR}/filetypes.conf

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	src/core/datadir.cpp
SUBST_SED.paths=	-e 's,/etc/highlight,${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,/usr/share,${PREFIX}/share,g'

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
