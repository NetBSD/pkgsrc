# $NetBSD: Makefile,v 1.4 2001/08/16 06:55:55 agc Exp $

DISTNAME=       dictd-1.4.9
PKGNAME=        dict-client-1.4.9
CATEGORIES=	textproc
MASTER_SITES=   ftp://ftp.cs.unc.edu/pub/users/faith/dict/ \
		ftp://ftp.dict.org/pub/dict/

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
