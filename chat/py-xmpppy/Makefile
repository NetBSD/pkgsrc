# $NetBSD: Makefile,v 1.23 2022/01/02 16:22:26 gdt Exp $

DISTNAME=	xmpppy-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_GITHUB:=xmpppy/}
GITHUB_PROJECT=	xmpppy

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://xmpppy.sourceforge.net/
COMMENT=	XMPP (Jabber) library for Python
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-expat>=0nb4:../../textproc/py-expat

USE_LANGUAGES=	# none

DOCDIR=		${PREFIX}/share/doc/py-xmpppy
EXDIR=		${PREFIX}/share/examples/py-xmpppy

INSTALLATION_DIRS+=	${DOCDIR} ${EXDIR}

post-install:
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${EXDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/docs/examples/*.py \
		${DESTDIR}${EXDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.html \
		${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.png \
		${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.css \
		${DESTDIR}${DOCDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
