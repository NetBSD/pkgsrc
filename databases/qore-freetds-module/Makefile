# $NetBSD: Makefile,v 1.33 2024/05/29 16:31:53 adam Exp $

DISTNAME=	qore-sybase-modules-1.2
PKGNAME=	${DISTNAME:S/sybase-modules/freetds-module/}
PKGREVISION=	8
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=qorelanguage/}
EXTRACT_SUFX=	.tar.bz2
GITHUB_PROJECT=	module-sybase
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	nros@NetBSD.org
HOMEPAGE=	http://www.qore.org/
COMMENT=	Freetds DB driver for qore
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++11
USE_TOOLS+=	pax
PTHREAD_OPTS+=	require

CONFIGURE_ARGS+=	--with-sybase=no
CONFIGURE_ARGS+=	--with-libsuffix=""

INSTALLATION_DIRS+=     share/doc/${PKGBASE}
post-install:
	cd ${WRKSRC}/docs/sybase && ${PAX} -wr * \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "options.mk"

.include "../../databases/freetds/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/qore/buildlink3.mk"
.include "../../lang/qore/module.mk"
.include "../../mk/bsd.pkg.mk"
