# $NetBSD: Makefile,v 1.5 2001/10/12 10:51:51 simonb Exp $

DISTNAME=       dictd-1.5.5
PKGNAME=        dict-client-1.5.5
CATEGORIES=	textproc
MASTER_SITES=   ftp://ftp.dict.org/pub/dict/

MAINTAINER=	mike@ethmoid.org
HOMEPAGE=	http://www.dict.org/
COMMENT=	Dictionary Service Protocol client

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

ALL_TARGET=	dict
INSTALL_TARGET=	install.dict

FILESDIR=	${.CURDIR}/../../textproc/dict-server/files
PATCHDIR=	${.CURDIR}/../../textproc/dict-server/patches
DISTINFO_FILE=	${.CURDIR}/../../textproc/dict-server/distinfo

.include "../../mk/bsd.pkg.mk"
