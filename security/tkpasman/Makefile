# $NetBSD: Makefile,v 1.1.1.1 2002/12/05 21:21:55 jmmv Exp $
#

DISTNAME=	TkPasMan-2.2
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	security
MASTER_SITES=	http://www.xs4all.nl/~wbsoft/linux/projects/

MAINTAINER=	jmmv@hispabsd.org
HOMEPAGE=	http://www.xs4all.nl/~wbsoft/linux/tkpasman.html
COMMENT=	Username and password manager that uses the Tk toolkit

USE_BUILDLINK2=		YES

CONFIG_SUBST=		PREFIX="${PREFIX}"
CONFIG_SUBST+=		SHELL="${SH}"
CONFIG_SUBST+=		INSTALL_SCRIPT="${INSTALL_SCRIPT}"
CONFIG_SUBST_SED=	${CONFIG_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

.include "../../mk/bsd.prefs.mk"

# SSL support
.if defined(TKPASMAN_USE_SSL) && ${TKPASMAN_USE_SSL} == "YES"
.  include "../../security/openssl/buildlink2.mk"
CONFIG_SUBST+=		USE_OPENSSL="true"
CONFIG_SUBST+=		OPENSSL="${BUILDLINK_PREFIX.openssl}/bin/openssl"
.else
CONFIG_SUBST+=		USE_OPENSSL="false"
CONFIG_SUBST+=		OPENSSL=""
.endif

ALL_TARGET=		tkpasman

post-extract:
	${MV} ${WRKSRC}/config ${WRKSRC}/config.in

do-configure:
	${SED} ${CONFIG_SUBST_SED} ${WRKSRC}/config.in > ${WRKSRC}/config

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkpasman ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tkpasman
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/tkpasman

.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
