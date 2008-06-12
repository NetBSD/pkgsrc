# $NetBSD: Makefile,v 1.8 2008/06/12 02:14:42 joerg Exp $
#

DISTNAME=		pylibpcap-0.5.1
PKGNAME=		${PYPKGPREFIX}-libpcap-0.5.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pylibpcap/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pylibpcap.sourceforge.net/
COMMENT=		Python wrapper for libpcap

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=		yes
BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.9.3nb1

pre-build:
	(cd ${WRKSRC} && ${PYTHONBIN} mk-constants.py)

.include "../../lang/python/extension.mk"
#.include "../../devel/swig/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
