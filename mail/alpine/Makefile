# $NetBSD: Makefile,v 1.9 2007/12/29 19:49:43 abs Exp $
#

DISTNAME=	alpine-1.00
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cac.washington.edu/alpine/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.washington.edu/alpine/
COMMENT=	Program for Internet News and E-mail

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-ssl-dir=${SSLBASE:Q}
CONFIGURE_ARGS+= --with-system-pinerc=${PKG_SYSCONFDIR}/pine.conf
CONFIGURE_ARGS+= --with-system-fixed-pinerc=${PKG_SYSCONFDIR}/pine.conf.fixed

USE_LIBTOOL=	yes

INSTALLATION_DIRS=	bin ${PKMANDIR}/man1

PKG_OPTIONS_VAR=	PKG_OPTIONS.alpine
PKG_SUPPORTED_OPTIONS=	pinepwd
PKG_SUGGESTED_OPTIONS=	pinepwd

.include "../../mk/bsd.options.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+= --without-pthread
.endif

.if !empty(PKG_OPTIONS:Mpinepwd)
CONFIGURE_ARGS+= --with-passfile=.pinepwd
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/alpine/alpine ${DESTDIR}${PREFIX}/bin/alpine
	${INSTALL_MAN} ${WRKSRC}/doc/alpine.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/alpine.1

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
