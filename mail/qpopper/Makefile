# $NetBSD: Makefile,v 1.47.2.1 2005/06/05 18:35:25 salo Exp $
#

DISTNAME=		qpopper${VERSION}
PKGNAME=		qpopper-${VERSION}
CATEGORIES=		mail
MASTER_SITES=		${QPOPPER_MASTER_SITES}

MAINTAINER=		mellon@fugue.com
HOMEPAGE=		${QPOPPER_HOMEPAGE}
COMMENT=		Qualcomm's POP server for Eudora

.include "Makefile.common"

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes

RCD_SCRIPTS=		qpopper
MESSAGE_SUBST+=		RCD_SCRIPTS=${RCD_SCRIPTS} \
			RCD_SCRIPTS_DIR=${RCD_SCRIPTS_DIR}

PKG_USERS?=		${QPOPPER_USER}:${QPOPPER_GROUP}
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

.include "../../mk/bsd.pkg.mk"
