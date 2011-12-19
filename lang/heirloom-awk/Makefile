# $NetBSD: Makefile,v 1.4 2011/12/19 01:31:37 dholland Exp $

PKGNAME=	heirloom-awk-${HEIRLOOM_VER}
CATEGORIES=	textproc lang
LICENSE=	gnu-gpl-v2 AND original-bsd

MAKE_JOBS_SAFE=	no

MAKE_FLAGS+=	SUBDIRS="build oawk nawk"

NEED_LIBUXRE=	1
USE_TOOLS=	yacc lex

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	${.CURDIR}/DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../devel/libuxre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
