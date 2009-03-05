# $NetBSD: Makefile,v 1.16 2009/03/05 17:40:04 tnn Exp $

DISTNAME=		duplicity-0.5.10
CATEGORIES=		sysutils net
MASTER_SITES=		http://savannah.nongnu.org/download/duplicity/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.nongnu.org/duplicity/
COMMENT=		Remote encrypting incremental backup utility

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_API_DEPENDS.librsync+=	librsync>=0.9.6
PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED= 25 24

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	fixing mandir
SUBST_FILES.fix-paths=		setup.py
SUBST_SED.fix-paths=		-e 's,share/man/man1,${PKGMANDIR}/man1,'

.include "../../devel/librsync/buildlink3.mk"
.include "../../net/py-boto/buildlink3.mk"
.include "../../security/py-gnupg/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
