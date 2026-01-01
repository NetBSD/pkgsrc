# $NetBSD: Makefile,v 1.66 2026/01/01 11:19:14 wiz Exp $

DISTNAME=	roundup-2.5.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=r/roundup/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.roundup-tracker.org/
COMMENT=	Issue tracking system with command-line, web and email clients
LICENSE=	mit AND zpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# empty

REPLACE_PYTHON+=		frontends/roundup.cgi

.include "../../mk/bsd.fast.prefs.mk"

.if ${PKGMANDIR} != "share/man"
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/roundup-admin.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/roundup-demo.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/roundup-mailgw.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/roundup-server.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endif

# as of 2.5.0
# 1 failed, 1268 passed, 1119 skipped, 2 warnings

.include "../../lang/python/wheel.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
