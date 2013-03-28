# $NetBSD: Makefile,v 1.18 2013/03/28 21:22:57 joerg Exp $
#

VERS=			1.7.6
DISTNAME=		pysvn-${VERS}
PKGNAME=		${PYPKGPREFIX}-pysvn-${VERS}
CATEGORIES=		devel
MASTER_SITES=	http://pysvn.barrys-emacs.org/source_kits/

MAINTAINER=		helgoman@users.sourceforge.net
HOMEPAGE=		http://pysvn.tigris.org/
COMMENT=		Python interface to Subversion
LICENSE=		apache-1.1

DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

USE_LANGUAGES=		c

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "DragonFly"
BUILDLINK_TRANSFORM+=	rm:-lresolv
.endif

.include "../../devel/subversion-base/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
