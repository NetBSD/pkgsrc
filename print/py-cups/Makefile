# $NetBSD: Makefile,v 1.57 2023/11/08 13:20:43 wiz Exp $

DISTNAME=	pycups-1.9.73
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
PKGREVISION=	24
CATEGORIES=	print python
MASTER_SITES=	http://cyberelk.net/tim/data/pycups/
MASTER_SITES+=	${MASTER_SITE_PYPI:=p/pycups/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://cyberelk.net/tim/software/pycups/
COMMENT=	Python bindings for the CUPS API
LICENSE=	gnu-gpl-v2

CFLAGS+=	-DVERSION=\"${PKGVERSION_NOREV}\"

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fix cups paths.
SUBST_FILES.paths=	cupsconnection.c
SUBST_SED.paths=	-e 's:"/usr/share/cups":"${BUILDLINK_PREFIX.cups-base}/share/cups/", "/usr/share/cups":'
SUBST_STAGE.paths=	pre-configure

.include "../../lang/python/egg.mk"
.include "../../print/cups-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
