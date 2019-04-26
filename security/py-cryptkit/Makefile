# $NetBSD: Makefile,v 1.25 2019/04/26 14:12:45 maya Exp $

DISTNAME=	cryptkit-0.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cryptkit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/cryptkit/
COMMENT=	Python Cryptographic Toolkit

PYTHON_VERSIONS_INCOMPATIBLE=	36 37 # not yet ported as of 0.9

CPPFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t -Du_int32_t=uint32_t -Du_int64_t=uint64_t

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
