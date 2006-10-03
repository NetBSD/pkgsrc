# $NetBSD: Makefile,v 1.28.2.1 2006/10/03 14:29:33 ghen Exp $

DISTNAME=       dictd-1.9.15
PKGNAME=        dict-client-1.9.15
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=   ftp://ftp.dict.org/pub/dict/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dict.org/
COMMENT=	Dictionary Service Protocol client

USE_TOOLS+=		gmake flex yacc
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-cflags=${CFLAGS:M*:Q}
CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--enable-dictorg

BUILD_TARGET=	dict
INSTALL_TARGET=	install.dict

FILESDIR=	${.CURDIR}/../../textproc/dict-server/files
PATCHDIR=	${.CURDIR}/../../textproc/dict-server/patches
DISTINFO_FILE=	${.CURDIR}/../../textproc/dict-server/distinfo

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
