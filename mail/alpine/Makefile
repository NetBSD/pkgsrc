# $NetBSD: Makefile,v 1.34 2014/02/12 23:18:06 tron Exp $
#

DISTNAME=	alpine-2.11
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://patches.freeiz.com/alpine/release/src/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://patches.freeiz.com/alpine/release/
COMMENT=	Program for Internet News and E-mail
LICENSE=	apache-2.0

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-ssl-dir=${SSLBASE}
CONFIGURE_ARGS+= --with-ssl-certs-dir=${SSLCERTS:Q}
CONFIGURE_ARGS+= --with-ssl-include-dir=${SSLBASE}/include
CONFIGURE_ARGS+= --with-ssl-lib-dir=${SSLBASE}/lib
CONFIGURE_ARGS+= --with-system-pinerc=${PKG_SYSCONFDIR}/pine.conf
CONFIGURE_ARGS+= --with-system-fixed-pinerc=${PKG_SYSCONFDIR}/pine.conf.fixed
# disabled, for Web Alpine Support
CONFIGURE_ARGS+=	--without-tcl

USE_LIBTOOL=	yes

MAKE_JOBS_SAFE=         no
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && empty(OS_VERSION:M4.99.*) && empty(OS_VERSION:M[5-9]*)
CONFIGURE_ARGS+= --without-pthread
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/alpine/alpine ${DESTDIR}${PREFIX}/bin/alpine
	${INSTALL_MAN} ${WRKSRC}/doc/alpine.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/alpine.1

.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
