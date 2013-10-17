# $NetBSD: Makefile,v 1.5 2013/10/17 07:56:41 wiz Exp $
#

DISTNAME=	libmtag-python-0.3.0
PKGNAME=	${PYPKGPREFIX}-libmtag-0.3.0
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://libmtag.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libmtag/
COMMENT=	Python binding for libmtag

USE_TOOLS+=	pkg-config

EGG_NAME=	MTag-0.0.0

.include "../../lang/python/distutils.mk"
.include "../../audio/libmtag/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
