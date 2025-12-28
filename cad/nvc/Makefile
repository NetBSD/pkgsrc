# $NetBSD: Makefile,v 1.1 2025/12/28 05:42:54 ryoon Exp $

DISTNAME=	nvc-1.18.2
CATEGORIES=	cad
MASTER_SITES=	https://www.nickg.me.uk/files/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.nickg.me.uk/nvc/
COMMENT=	VHDL compiler and simulator implementing IEEE 1076-2008
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++

USE_TOOLS+=	bash:run gmake pkg-config

REPLACE_BASH+=	contrib/*.sh

GNU_CONFIGURE=	yes

# Cannot perform in-tree build.
OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure

# Do not create almost empty object files
# with warning, "plugin needed to handle lto object".
CONFIGURE_ARGS+=	--disable-lto

NOT_PAX_MPROTECT_SAFE+=	bin/nvc

pre-configure:
	# Cannot perform in-tree build.
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/capstone/buildlink3.mk"
.include "../../devel/check/buildlink3.mk"
.include "../../devel/libdwarf/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
