# $NetBSD: Makefile,v 1.2 2012/10/03 00:02:43 asau Exp $
#

DISTNAME=	xmpppy-0.5.0rc1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmpppy/}

MAINTAINER=	schnoebe@netbsd.org
HOMEPAGE=	http://xmpppy.sourceforge.net/
COMMENT=	XMPP (Jabber) library for Python
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-dns>=1.7.1:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-expat>=0nb4:../../textproc/py-expat

USE_LANGUAGES=	# none

PYDISTUTILSPKG=		yes

DOCDIR=		${PREFIX}/share/doc/py-xmpppy
EXDIR=		${PREFIX}/share/examples/py-xmpppy

INSTALLATION_DIRS+=	${DOCDIR} ${EXDIR}

post-install:
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${EXDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/doc/examples/*.py \
		${DESTDIR}${EXDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html \
		${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.png \
		${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.css \
		${DESTDIR}${DOCDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
