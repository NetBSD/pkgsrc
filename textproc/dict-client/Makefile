# $NetBSD: Makefile,v 1.20 2005/03/29 12:15:41 adam Exp $

DISTNAME=       dictd-1.9.15
PKGNAME=        dict-client-1.9.15
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=   ftp://ftp.dict.org/pub/dict/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.dict.org/
COMMENT=	Dictionary Service Protocol client

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-cflags="${CFLAGS}"
CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--enable-dictorg

BUILD_TARGET=	dict
INSTALL_TARGET=	install.dict

FILESDIR=	${.CURDIR}/../../textproc/dict-server/files
PATCHDIR=	${.CURDIR}/../../textproc/dict-server/patches
DISTINFO_FILE=	${.CURDIR}/../../textproc/dict-server/distinfo

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
