# $NetBSD: Makefile,v 1.2 2016/03/05 11:29:25 jperkin Exp $

DISTNAME=	qore-asn1-module-0.0.3
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qore/}

MAINTAINER=	nros@users.sourceforge.net
HOMEPAGE=	http://www.qore.org/
COMMENT=	ASN.1 Qore module
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
PTHREAD_OPTS+=	require

INSTALLATION_DIRS+=     share/doc/qore-asn1-module
post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/asn1-module-doc.html \
		${DESTDIR}${PREFIX}/share/doc/qore-asn1-module

.include "options.mk"
.include "../../lang/qore/module.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/qore/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
