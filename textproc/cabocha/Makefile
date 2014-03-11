# $NetBSD: Makefile,v 1.7 2014/03/11 09:43:06 obache Exp $
#

.include "Makefile.common"

COMMENT=	Yet another Japanese Dependency Structure Analyzer

NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

INSTALL_MAKE_FLAGS+=	confdir=${PREFIX}/share/examples

CONF_FILES=	share/examples/cabocharc ${PKG_SYSCONFDIR}/cabocharc

TEST_TARGET=	check

BUILDLINK_API_DEPENDS.crfpp+=	CRF++>=0.55
.include "../../textproc/CRF++/buildlink3.mk"
BUILDLINK_API_DEPENDS.mecab+=	mecab>=0.993
.include "../../textproc/mecab/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
