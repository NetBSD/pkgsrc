# $NetBSD: Makefile,v 1.7 2002/12/27 02:40:18 uebayasi Exp $

DISTNAME=       dictd-1.8.0
PKGNAME=        dict-client-1.8.0
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=   ftp://ftp.dict.org/pub/dict/

MAINTAINER=	mike@ethmoid.org
HOMEPAGE=	http://www.dict.org/
COMMENT=	Dictionary Service Protocol client

DEPENDS=	dict-server>=1.8.0nb1:../../textproc/dict-server

USE_BUILDLINK2=	# defined
USE_GMAKE=	# defined
GNU_CONFIGURE=	# defined

ALL_TARGET=	dict
INSTALL_TARGET=	install.dict

FILESDIR=	${.CURDIR}/../../textproc/dict-server/files
PATCHDIR=	${.CURDIR}/../../textproc/dict-server/patches
DISTINFO_FILE=	${.CURDIR}/../../textproc/dict-server/distinfo

.include "../../devel/libtool/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
