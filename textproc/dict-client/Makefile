# $NetBSD: Makefile,v 1.11 2004/01/24 15:13:19 grant Exp $

DISTNAME=       dictd-1.8.0
PKGNAME=        dict-client-1.8.0
PKGREVISION=	2
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

# XXX This is needed by libltdl.
.include "../../devel/libtool/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
