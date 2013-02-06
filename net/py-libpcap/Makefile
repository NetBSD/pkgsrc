# $NetBSD: Makefile,v 1.12 2013/02/06 19:31:00 jperkin Exp $
#

DISTNAME=		pylibpcap-0.6.2
PKGNAME=		${PYPKGPREFIX}-libpcap-0.6.2
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pylibpcap/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pylibpcap.sourceforge.net/
COMMENT=		Python wrapper for libpcap
LICENSE=		modified-bsd

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.9.3nb1

pre-build:
	(cd ${WRKSRC} && ${PYTHONBIN} mk-constants.py)

.include "../../lang/python/distutils.mk"
#.include "../../devel/swig/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
