# $NetBSD: Makefile,v 1.22 2012/09/05 10:05:43 wiz Exp $

DISTNAME=		duplicity-0.6.19
CATEGORIES=		sysutils net
MASTER_SITES=		http://code.launchpad.net/duplicity/0.6-series/${PKGVERSION_NOREV}/+download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.nongnu.org/duplicity/
COMMENT=		Remote encrypting incremental backup utility
LICENSE=		gnu-gpl-v2

DEPENDS+=	gnupg>=1.0.0:../../security/gnupg
DEPENDS+=	${PYPKGPREFIX}-boto>=1.6a:../../net/py-boto

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes

REPLACE_PYTHON+=	*.py
REPLACE_PYTHON+=	bin/*
REPLACE_PYTHON+=	duplicity/*.py

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	fixing hard coded dirs
SUBST_FILES.fix-paths=		setup.py
SUBST_SED.fix-paths=		-e 's,share/man/man1,${PKGMANDIR}/man1,'
SUBST_SED.fix-paths+=		-e 's,share/locale,${PKGLOCALEDIR}/locale,'

BUILDLINK_API_DEPENDS.librsync+=	librsync>=0.9.6
.include "../../devel/librsync/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
