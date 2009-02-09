# $NetBSD: Makefile,v 1.12 2009/02/09 21:09:22 joerg Exp $
#

DISTNAME=		Mixminion-0.0.7.1
PKGNAME=		${DISTNAME:S/M/m/}
PKGREVISION=		3
CATEGORIES=		security mail
MASTER_SITES=		http://mixminion.net/dist/0.0.7.1/

MAINTAINER=		pdh@wiredyne.com
HOMEPAGE=		http://mixminion.net/
COMMENT=		Mixminion impedes message traffic analysis

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7d

CRYPTO=				YES
PYTHON_VERSIONS_ACCEPTED=	23
PYDISTUTILSPKG=			YES

TEST_TARGET=			test

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	setup.py
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_STAGE.paths=	post-patch

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
