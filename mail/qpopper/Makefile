# $NetBSD: Makefile,v 1.38 2003/11/12 03:39:41 jschauma Exp $
#

DISTNAME=		qpopper${VERSION}
PKGNAME=		qpopper-${VERSION}
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.qualcomm.com/eudora/servers/unix/popper/

PATCH_SITES=		ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=		qpopper-4.0.5-ipv6-20030313.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=		mellon@fugue.com
HOMEPAGE=		http://www.eudora.com/qpopper/
COMMENT=		Qualcomm's POP server for Eudora

.include "Makefile.common"

USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}

PKG_USERS?=		${QPOPPER_USER}
MAKE_ENV+=		BINGRP=${BINGRP}

pre-build:
	${SED}	-e "s|/usr/local/lib|${PREFIX}/libexec|g"		\
		${WRKSRC}/man/popper.8 > ${WRKSRC}/man/popper.8.$$ &&	\
	${MV} -f ${WRKSRC}/man/popper.8.$$ ${WRKSRC}/man/popper.8

post-install:
	${INSTALL_DATA} ${WRKSRC}/License.txt				\
		${PREFIX}/share/doc/qpopper.License
	${INSTALL_DATA} ${WRKSRC}/samples/qpopper.config		\
		 ${PREFIX}/share/examples

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
