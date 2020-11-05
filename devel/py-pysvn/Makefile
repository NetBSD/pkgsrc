# $NetBSD: Makefile,v 1.45 2020/11/05 09:07:58 ryoon Exp $
#

VERS=		1.7.6
DISTNAME=	pysvn-${VERS}
PKGNAME=	${PYPKGPREFIX}-pysvn-${VERS}
PKGREVISION=	24
CATEGORIES=	devel
MASTER_SITES=	http://pysvn.barrys-emacs.org/source_kits/

MAINTAINER=		helgoman@users.sourceforge.net
HOMEPAGE=		http://pysvn.tigris.org/
COMMENT=		Python interface to Subversion
LICENSE=		apache-1.1

DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

USE_LANGUAGES=		c

BUILDLINK_TRANSFORM.DragonFly+=	rm:-lresolv

SUBST_CLASSES+=		rpath-flg
SUBST_STAGE.rpath-flg=	pre-configure
SUBST_FILES.rpath-flg=	Source/setup_configure.py
SUBST_SED.rpath-flg=	-e 's|-Wl,--rpath|${COMPILER_RPATH_FLAG}|g'

.include "../../devel/subversion-base/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
