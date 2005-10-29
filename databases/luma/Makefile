# $NetBSD: Makefile,v 1.4 2005/10/29 01:44:35 kristerw Exp $
#

DISTNAME=		luma-2.2.1
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=luma/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://luma.sourceforge.net/
COMMENT=		LDAP browser

SUBST_CLASSES+=		luma
SUBST_STAGE.luma=	pre-configure
SUBST_FILES.luma=	bin/luma
SUBST_SED.luma=		-e "s|@PREFIX@|${PREFIX}|"
PYTHON_PATCH_SCRIPTS=	bin/luma

do-build:
	(cd ${WRKSRC} && ${PYTHONBIN} install.py --compile-only)

do-install:
	(cd ${WRKSRC} && ${PYTHONBIN} install.py --prefix=${PREFIX})
	${RM} -f ${PREFIX}/bin/luma.orig

.include "../../lang/python/application.mk"
.include "../../databases/py-ldap/buildlink3.mk"
.include "../../x11/py-qt3-base/buildlink3.mk"
.include "../../x11/py-qt3-modules/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
