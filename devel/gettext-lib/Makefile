# $NetBSD: Makefile,v 1.5 2001/02/16 14:38:25 wiz Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1998/08/09 15:13:33 kuriyama Exp
#

DISTNAME=		gettext-0.10.35
PKGNAME=		gettext-lib-0.10.35nb1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=gettext/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/gettext/gettext.html
COMMENT=		tools for providing messages in different languages, libintl only

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--with-included-gettext

PATCHDIR=		${.CURDIR}/../../devel/gettext/patches
PATCH_SUM_FILE=		${.CURDIR}/../../devel/gettext/files/patch-sum
INSTALL_TARGET=		install-exec

makepatchsum::

do-build:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC}/intl && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${ALL_TARGET}

do-install:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC}/intl && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${INSTALL_TARGET}

.include "../../mk/bsd.pkg.mk"
