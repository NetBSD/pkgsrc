# $NetBSD: Makefile,v 1.40 2024/02/16 20:31:13 nros Exp $

DISTNAME=	qore-sqlite3-module-1.0.2
PKGREVISION=	12
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=qorelanguage/}
GITHUB_PROJECT=	module-sqlite3
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	nros@NetBSD.org
HOMEPAGE=	http://www.qore.org/
COMMENT=	SQLite module for Qore
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++11
PTHREAD_OPTS+=	native

CONFIGURE_ARGS+=	--with-sqlite3=${BUILDLINK_PREFIX.sqlite3}
CONFIGURE_ARGS+=	--with-libsuffix=""

INSTALLATION_DIRS+=     share/doc/${PKGBASE}
post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/sqlite3-module-doc.html \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "options.mk"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/qore/buildlink3.mk"
.include "../../lang/qore/module.mk"
.include "../../mk/bsd.pkg.mk"
