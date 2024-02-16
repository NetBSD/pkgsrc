# $NetBSD: Makefile,v 1.19 2024/02/16 20:31:12 nros Exp $

DISTNAME=	qore-mysql-module-2.1
PKGREVISION=	8
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=qorelanguage/}
EXTRACT_SUFX=	.tar.bz2
GITHUB_PROJECT=	module-mysql
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	nros@NetBSD.org
HOMEPAGE=	http://www.qore.org/
COMMENT=	MySQL DB driver for Qore
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++11
USE_TOOLS+=	gmake pax
PTHREAD_OPTS+=	native

CONFIGURE_ARGS+=	--with-libsuffix=""

#install docs
INSTALLATION_DIRS+=	share/doc/${PKGBASE}
post-install:
	cd ${WRKSRC}/docs/mysql && ${PAX} -wr * \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "options.mk"

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/qore/buildlink3.mk"
.include "../../lang/qore/module.mk"
.include "../../mk/bsd.pkg.mk"
