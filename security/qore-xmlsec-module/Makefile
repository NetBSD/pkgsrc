# $NetBSD: Makefile,v 1.8 2020/06/02 08:24:42 adam Exp $

DISTNAME=	qore-xmlsec-module-0.0.2
PKGREVISION=	10
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qore/}

MAINTAINER=	nros@users.sourceforge.net
HOMEPAGE=	http://www.qore.org/
COMMENT=	XMLSec module for Qore
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++11
PTHREAD_OPTS+=	native

CONFIGURE_ARGS+=	--with-xmlsec-dir=${BUILDLINK_PREFIX.xmlsec1}
CONFIGURE_ARGS+=	--with-libxml2-dir=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-qore-dir=${BUILDLINK_PREFIX.qore}

INSTALLATION_DIRS+=     share/doc/${PKGBASE}
post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/xmlsec-module-doc.html \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../security/xmlsec1/buildlink3.mk"
.include "../../lang/qore/buildlink3.mk"
.include "../../lang/qore/module.mk"
.include "../../mk/bsd.pkg.mk"
