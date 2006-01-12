# $NetBSD: Makefile,v 1.3 2006/01/12 17:36:01 wiz Exp $
#

DISTNAME=		pylibpcap-0.5
PKGNAME=		${PYPKGPREFIX}-libpcap-0.5
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pylibpcap/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://pylibpcap.sourceforge.net/
COMMENT=		Python wrapper for libpcap

PYDISTUTILSPKG=		yes
BUILDLINK_DEPENDS.libpcap+=	libpcap>=0.9.3nb1

pre-build:
	(cd ${WRKSRC} && ${PYTHONBIN} mk-constants.py)

.include "../../lang/python/extension.mk"
#.include "../../devel/swig/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
