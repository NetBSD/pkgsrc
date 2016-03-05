# $NetBSD: Makefile,v 1.2 2016/03/05 11:27:44 jperkin Exp $

DISTNAME=	qore-mysql-module-2.0.1
PKGREVISION=	5
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qore/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	nros@users.sourceforge.net
HOMEPAGE=	http://www.qore.org/
COMMENT=	MySQL DB driver for Qore
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pax
PTHREAD_OPTS+=	native

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
