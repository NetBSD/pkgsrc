# $NetBSD: Makefile,v 1.16 2022/01/10 22:15:04 wiz Exp $

DISTNAME=	libmtag-python-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python//}
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://libmtag.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/archive/p/libmtag/
COMMENT=	Python binding for libmtag

USE_TOOLS+=	pkg-config

EGG_NAME=	MTag-0.0.0

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.3.1

.include "../../lang/python/egg.mk"
.include "../../audio/libmtag/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
