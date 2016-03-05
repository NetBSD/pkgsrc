# $NetBSD: Makefile,v 1.2 2016/03/05 11:28:19 jperkin Exp $

DISTNAME=	qore-openldap-module-1.0
PKGREVISION=	5
CATEGORIES=	databases
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=qore/}
EXTRACT_SUFX=   .tar.bz2

MAINTAINER=	nros@users.sourceforge.net
COMMENT=	Openldap module for Qore
HOMEPAGE=	http://www.qore.org/
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pax
PTHREAD_OPTS+=	native

#install docs
INSTALLATION_DIRS+=share/doc/${PKGBASE}
post-install:
	cd ${WRKSRC}/docs/openldap && ${PAX} -wr * \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "options.mk"

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/qore/buildlink3.mk"
.include "../../lang/qore/module.mk"
.include "../../mk/bsd.pkg.mk"
