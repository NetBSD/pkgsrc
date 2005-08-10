# $NetBSD: Makefile,v 1.1.1.1 2005/08/10 13:51:01 drochner Exp $
#

DISTNAME=		pylibpcap-0.5
PKGNAME=		${PYPKGPREFIX}-libpcap-0.5
CATEGORIES=		net
MASTER_SITES=		http://heanet.dl.sourceforge.net/sourceforge/pylibpcap/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://pylibpcap.sourceforge.net/
COMMENT=		Python wrapper for libpcap

PYDISTUTILSPKG=		yes
BUILDLINK_DEPENDS.libpcap+=	libpcap>=0.9.3nb1

pre-build:
	(cd ${WRKSRC} && ${PYTHONBIN} mk-constants.py)

.include "../../lang/python/extension.mk"
#.include "../../devel/swig13/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
