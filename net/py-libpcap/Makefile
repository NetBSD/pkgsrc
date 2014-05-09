# $NetBSD: Makefile,v 1.15 2014/05/09 07:37:15 wiz Exp $

DISTNAME=	pylibpcap-0.6.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pylibpcap/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pylibpcap.sourceforge.net/
COMMENT=	Python wrapper for libpcap
LICENSE=	modified-bsd

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.9.3nb1

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.6.4

pre-build:
	(cd ${WRKSRC} && ${PYTHONBIN} mk-constants.py)

.include "../../lang/python/distutils.mk"
#.include "../../devel/swig/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
