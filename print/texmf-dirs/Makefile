# $NetBSD: Makefile,v 1.7 2006/08/10 03:35:33 minskim Exp $

DISTNAME=	texmf-dirs-1.3
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Local TeX directory structure

NO_BUILD=	yes
NO_CONFIGURE=	yes
NO_CHECKSUM=	yes
NO_EXTRACT=	yes
USE_LANGUAGES=	# empty
WRKSRC=		${WRKDIR}

.include "dirs.mk"

.include "../../mk/tex.buildlink3.mk"
REQD_DIRS+=	${TEXMF_DIRS:O:S/^/${PKG_LOCALTEXMFPREFIX}\//}
.if ${TEX_TYPE} == "teTeX3"
BUILDLINK_API_DEPENDS.teTeX-bin+=	teTeX-bin>=3.0nb10
.endif

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
