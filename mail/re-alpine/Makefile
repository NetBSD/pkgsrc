# $NetBSD: Makefile,v 1.12 2014/02/12 23:18:09 tron Exp $
#

DISTNAME=	re-alpine-2.02
PKGREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=re-alpine/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://sourceforge.net/projects/re-alpine/
COMMENT=	Console-based mail and news client
LICENSE=	apache-2.0

CONFLICTS=	alpine-[0-9]*

.include "options.mk"

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-ssl-dir=${SSLBASE}
CONFIGURE_ARGS+= --with-ssl-certs-dir=${SSLCERTS:Q}
CONFIGURE_ARGS+= --with-ssl-include-dir=${SSLBASE}/include
CONFIGURE_ARGS+= --with-ssl-lib-dir=${SSLBASE}/lib
CONFIGURE_ARGS+= --with-system-pinerc=${PKG_SYSCONFDIR}/pine.conf
CONFIGURE_ARGS+= --with-system-fixed-pinerc=${PKG_SYSCONFDIR}/pine.conf.fixed
CONFIGURE_ARGS+= --with-smime

USE_LIBTOOL=	yes

MAKE_JOBS_SAFE=         no
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && empty(OS_VERSION:M4.99.*) && empty(OS_VERSION:M[5-9]*)
CONFIGURE_ARGS+= --without-pthread
.endif

.if ${OPSYS} == "MirBSD"
SUBST_CLASSES+=			mirbsd
SUBST_STAGE.mirbsd=		pre-configure
SUBST_FILES.mirbsd=		configure
SUBST_SED.mirbsd=		-e 's,\*-\*-openbsd,*-*-mirbsd,g'
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/alpine/alpine ${DESTDIR}${PREFIX}/bin/alpine
	${INSTALL_MAN} ${WRKSRC}/doc/alpine.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/alpine.1

.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
