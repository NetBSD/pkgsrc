# $NetBSD: Makefile,v 1.2 2001/10/18 15:20:10 veego Exp $

DISTNAME=		gettext-0.10.35
PKGNAME=		gettext-m4-0.10.35
SVR4_PKGNAME=		gttm4
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=gettext/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/gettext/gettext.html
COMMENT=		autoconf/automake m4 files for GNU NLS library

CONFLICTS=		gettext<=0.10.35nb1
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-included-gettext

PATCHDIR=		${.CURDIR}/../../devel/gettext/patches
DISTINFO_FILE=		${.CURDIR}/../../devel/gettext/distinfo

do-build:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC}/m4 && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${ALL_TARGET}

do-install:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC}/m4 && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${INSTALL_TARGET}

.include "../../mk/bsd.pkg.mk"
