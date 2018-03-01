# $NetBSD: Makefile,v 1.37.38.2 2018/03/01 09:30:46 cheusov Exp $

.include "../../textproc/dict-server/Makefile.common"

PKGNAME=	${DISTNAME:S/dictd/dict-client/}
CATEGORIES=	textproc
COMMENT=	Dictionary Service Protocol client

LICENSE=		gnu-gpl-v2 AND mit

USE_TOOLS+=		gmake yacc lex
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

BUILD_TARGET=		dict
INSTALL_TARGET=		install.dict

FILESDIR=	${.CURDIR}/../../textproc/dict-server/files
DISTINFO_FILE=	${.CURDIR}/../../textproc/dict-server/distinfo

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libmaa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
