# $NetBSD: Makefile,v 1.31 2012/12/16 01:52:17 obache Exp $
#

DISTNAME=	alpine-2.00
PKGREVISION=	8
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cac.washington.edu/alpine/
DIST_SUBDIR=	alpine-2.00a
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.washington.edu/alpine/
COMMENT=	Program for Internet News and E-mail
LICENSE=	apache-2.0

.include "options.mk"

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
