# $NetBSD: Makefile,v 1.25 2022/01/10 20:37:22 wiz Exp $

DISTNAME=	pylibpcap-0.6.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pylibpcap/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pylibpcap.sourceforge.net/
COMMENT=	Python wrapper for libpcap
LICENSE=	modified-bsd

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.9.3nb1

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.6.4

pre-build:
	(cd ${WRKSRC} && ${PYTHONBIN} mk-constants.py)

.include "../../lang/python/egg.mk"
#.include "../../devel/swig/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
