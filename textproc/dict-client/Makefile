# $NetBSD: Makefile,v 1.12 2004/03/28 21:43:26 jmmv Exp $

DISTNAME=       dictd-1.8.0
PKGNAME=        dict-client-1.8.0
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=   ftp://ftp.dict.org/pub/dict/

MAINTAINER=	mike@ethmoid.org
HOMEPAGE=	http://www.dict.org/
COMMENT=	Dictionary Service Protocol client

USE_BUILDLINK2=	# defined
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	# defined

ALL_TARGET=	dict
INSTALL_TARGET=	install.dict

FILESDIR=	${.CURDIR}/../../textproc/dict-server/files
PATCHDIR=	${.CURDIR}/../../textproc/dict-server/patches
DISTINFO_FILE=	${.CURDIR}/../../textproc/dict-server/distinfo

CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR}

# XXX This is needed by libltdl.
.include "../../devel/libtool/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
