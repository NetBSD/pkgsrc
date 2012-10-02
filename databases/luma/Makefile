# $NetBSD: Makefile,v 1.24 2012/10/02 21:25:21 asau Exp $

DISTNAME=	luma-2.3
PKGREVISION=	8
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=luma/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://luma.sourceforge.net/
COMMENT=	LDAP browser

AUTO_MKDIRS=		yes

SUBST_CLASSES+=		luma
SUBST_STAGE.luma=	pre-configure
SUBST_FILES.luma=	bin/luma
SUBST_SED.luma=		-e "s|@PREFIX@|${PREFIX}|"
PYTHON_PATCH_SCRIPTS=	bin/luma lib/luma/luma.py

post-extract:
	cd ${WRKSRC} && mv share/man man

do-build:
	(cd ${WRKSRC} && ${PYTHONBIN} install.py --compile-only)

do-install:
	rm ${WRKSRC}/bin/luma.orig
	cd ${WRKSRC} && ${PYTHONBIN} install.py --prefix=${DESTDIR}${PREFIX}
	cd ${WRKSRC} && \
	   ${INSTALL_MAN} man/man1/luma.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../databases/py-ldap/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../x11/py-qt3-base/buildlink3.mk"
.include "../../x11/py-qt3-modules/buildlink3.mk"
# XXX Please verify whether qt3-tools is really needed at run-time.
# If it is, then remove this comment.  If it is not, then remove
# this comment and the line below, and bump PKGREVISION.
#BUILDLINK_DEPMETHOD.qt3-tools=	full
.include "../../mk/bsd.pkg.mk"
