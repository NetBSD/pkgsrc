# $NetBSD: Makefile,v 1.12 2008/01/18 05:08:20 tnn Exp $
#

DISTNAME=	alpine-1.00
PKGREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cac.washington.edu/alpine/
DIST_SUBDIR=	alpine
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
PKG_SUPPORTED_OPTIONS=	pinepwd fancythreads
PKG_SUGGESTED_OPTIONS=	pinepwd

.include "../../mk/bsd.options.mk"

.if ${OPSYS} == "NetBSD" && empty(OS_VERSION:M4.99.*) && empty(OS_VERSION:M[5-9]*)
CONFIGURE_ARGS+= --without-pthread
.endif

.if !empty(PKG_OPTIONS:Mpinepwd)
CONFIGURE_ARGS+= --with-passfile=.pinepwd
.endif

.if !empty(PKG_OPTIONS:Mfancythreads)
PATCH_SITES+=		http://staff.washington.edu/chappa/alpine/patches/alpine-1.00/
PATCHFILES+=		fancy.patch.gz
PATCH_DIST_STRIP=	-p1
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/alpine/alpine ${DESTDIR}${PREFIX}/bin/alpine
	${INSTALL_MAN} ${WRKSRC}/doc/alpine.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/alpine.1

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
