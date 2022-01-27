# $NetBSD: Makefile,v 1.10 2022/01/27 17:52:03 nros Exp $

DISTNAME=	qore-openldap-module-1.2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=qorelanguage/}
EXTRACT_SUFX=	.tar.bz2
GITHUB_PROJECT=	module-openldap
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	nros@NetBSD.org
COMMENT=	Openldap module for Qore
HOMEPAGE=	http://www.qore.org/
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++11
USE_TOOLS+=	gmake pax
PTHREAD_OPTS+=	native

CONFIGURE_ARGS+=	--with-libsuffix=""

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
