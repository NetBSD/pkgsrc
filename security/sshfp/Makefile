# $NetBSD: Makefile,v 1.20 2022/06/30 11:18:48 nia Exp $

DISTNAME=	sshfp-1.2.2
PKGREVISION=	2
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_GITHUB:=xelerance/}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://github.com/xelerance/sshfp
COMMENT=	Print ssh host key fingerprint resource records
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-argparse-[0-9]*:../../devel/py-argparse
DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-ipcalc-[0-9]*:../../net/py-ipcalc

NO_BUILD=		yes
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
REPLACE_PYTHON+=	dane
REPLACE_PYTHON+=	sshfp

PYTHON_VERSIONS_ACCEPTED=	27

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dane ${DESTDIR}${PREFIX}/bin/dane
	${INSTALL_SCRIPT} ${WRKSRC}/sshfp ${DESTDIR}${PREFIX}/bin/sshfp
	${INSTALL_MAN} ${WRKSRC}/dane.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/sshfp.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
