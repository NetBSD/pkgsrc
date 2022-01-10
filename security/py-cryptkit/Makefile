# $NetBSD: Makefile,v 1.27 2022/01/10 18:27:55 wiz Exp $

DISTNAME=	cryptkit-0.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cryptkit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/cryptkit/
COMMENT=	Python Cryptographic Toolkit

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.9

CPPFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t -Du_int32_t=uint32_t -Du_int64_t=uint64_t

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
