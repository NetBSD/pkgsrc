# $NetBSD: Makefile,v 1.2 1999/07/28 16:26:12 tron Exp $

DISTNAME=       dictd-1.4.9
PKGNAME=        dict-client-1.4.9
CATEGORIES=	textproc
MASTER_SITES=   ftp://ftp.cs.unc.edu/pub/users/faith/dict/ \
		ftp://ftp.dict.org/pub/dict/

MAINTAINER=	mike@ethmoid.org
HOMEPAGE=	http://www.dict.org/

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

ALL_TARGET=	dict
INSTALL_TARGET=	install.dict

FILESDIR=	${.CURDIR}/../dict-server/files
PATCHDIR=	${.CURDIR}/../dict-server/patches

.include "../../mk/bsd.pkg.mk"
