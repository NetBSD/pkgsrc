# $NetBSD: Makefile,v 1.11.2.5 2002/08/23 01:14:18 jlam Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1998/08/09 15:13:33 kuriyama Exp
#

DISTNAME=		gettext-0.10.35
PKGNAME=		gettext-lib-0.10.35
PKGREVISION=		1
SVR4_PKGNAME=		gttli
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=gettext/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/gettext/gettext.html
COMMENT=		tools for providing messages in different languages, libintl only

CONFLICTS=		gettext<=0.10.35

# gettext-lib is needed to bootstrap shell/bash2, which is needed to
# bootstrap buildlink2.
#
USE_BUILDLINK2=		no

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--with-included-gettext
CONFIG_GUESS_OVERRIDE=	${WRKSRC}/config.guess
CONFIG_SUB_OVERRIDE=	${WRKSRC}/config.sub
CONFIGURE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"
MAKE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"

PATCHDIR=		${.CURDIR}/../../devel/gettext/patches
DISTINFO_FILE=		${.CURDIR}/../../devel/gettext/distinfo
INSTALL_TARGET=		install-exec

do-build:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC}/intl && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${ALL_TARGET}

do-install:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC}/intl && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${INSTALL_TARGET}

.include "../../mk/bsd.pkg.mk"

LDFLAGS:=	${LDFLAGS:N-L${LOCALBASE}/lib*}
