# $NetBSD: Makefile,v 1.43 2004/10/03 00:12:54 tv Exp $
#

DISTNAME=		qpopper${VERSION}
PKGNAME=		qpopper-${VERSION}
PKGREVISION=		5
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.qualcomm.com/eudora/servers/unix/popper/

PATCH_SITES=		ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=		qpopper-4.0.5-ipv6-20030313.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=		mellon@fugue.com
HOMEPAGE=		http://www.eudora.com/qpopper/
COMMENT=		Qualcomm's POP server for Eudora

.include "Makefile.common"

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
RCD_SCRIPTS=		qpopper
MESSAGE_SUBST+=		RCD_SCRIPTS=${RCD_SCRIPTS} \
			RCD_SCRIPTS_DIR=${RCD_SCRIPTS_DIR}

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

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
