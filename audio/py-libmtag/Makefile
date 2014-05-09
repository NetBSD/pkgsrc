# $NetBSD: Makefile,v 1.7 2014/05/09 07:36:54 wiz Exp $

DISTNAME=	libmtag-python-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python//}
CATEGORIES=	audio
MASTER_SITES=	http://libmtag.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libmtag/
COMMENT=	Python binding for libmtag

USE_TOOLS+=	pkg-config

EGG_NAME=	MTag-0.0.0

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.3.1

.include "../../lang/python/distutils.mk"
.include "../../audio/libmtag/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
