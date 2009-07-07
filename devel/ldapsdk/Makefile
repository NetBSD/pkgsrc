# $NetBSD: Makefile,v 1.31 2009/07/07 05:51:28 joerg Exp $

DISTNAME=	ldapsdk_12311998
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	2
CATEGORIES=	devel databases
MASTER_SITES=	${MASTER_SITE_MOZILLA_ALL:=directory/c-sdk/ancient/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mozilla.org/directory/
COMMENT=	LDAP C-SDK from the Mozilla project

CONFLICTS+=	openldap-client-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir
NOT_FOR_BULK_PLATFORM=	Linux-*-*

MAKE_JOBS_SAFE=	no

WRKSRC=		${WRKDIR}/mozilla
USE_TOOLS+=	gmake perl

PKG_SYSCONFSUBDIR=	ldapsdk
EGDIR=			${PREFIX}/share/examples/ldapsdk

MAKE_ENV+=	MOZILLA_CLIENT=1
MAKE_ENV+=	NO_MDUPDATE=1
MAKE_ENV+=	MOZ_LDAP_SDK=1
MAKE_FILE=	directory/ldapsdk.mk
BUILD_TARGET=	build

AUTO_MKDIRS=			yes

post-extract:
	${LN} -s FreeBSD.mk ${WRKSRC}/config/DragonFly.mk

do-configure:
	${ECHO} "PKG_SYSCONFDIR=${PKG_SYSCONFDIR}" >> ${WRKSRC}/config/rules.mk
	${ECHO} "EGDIR=${EGDIR}" >> ${WRKSRC}/config/rules.mk

do-install:
	cd ${WRKSRC}/dist/public/ldap \
	&& ${INSTALL_DATA} disptmpl.h lber.h ldap.h srchpref.h ${DESTDIR}${PREFIX}/include
	#
	# XXX kludge
	#
	${INSTALL_DATA} ${WRKSRC}/dist/${OPSYS}*/lib/libldap.a ${DESTDIR}${PREFIX}/lib/libldap.a
	${INSTALL_DATA} ${WRKSRC}/dist/${OPSYS}*/lib/liblber.a ${DESTDIR}${PREFIX}/lib/liblber.a
	${INSTALL_LIB} ${WRKSRC}/dist/${OPSYS}*/bin/libldap.so.1.0 ${DESTDIR}${PREFIX}/lib/libldap.so.1.0
	${LN} -sf libldap.so.1.0 ${DESTDIR}${PREFIX}/lib/libldap.so.1
	${LN} -sf libldap.so.1.0 ${DESTDIR}${PREFIX}/lib/libldap.so
	${INSTALL_LIB} ${WRKSRC}/dist/${OPSYS}*/bin/liblber.so.1.0 ${DESTDIR}${PREFIX}/lib/liblber.so.1.0
	${LN} -sf liblber.so.1.0 ${DESTDIR}${PREFIX}/lib/liblber.so.1
	${LN} -sf liblber.so.1.0 ${DESTDIR}${PREFIX}/lib/liblber.so
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/${OPSYS}*/etc/ldapfilter.conf      ${DESTDIR}${EGDIR}/ldapfilter.conf
	${INSTALL_DATA} ${WRKSRC}/dist/${OPSYS}*/etc/ldapsearchprefs.conf ${DESTDIR}${EGDIR}/ldapsearchprefs.conf
	${INSTALL_DATA} ${WRKSRC}/dist/${OPSYS}*/etc/ldapfriendly         ${DESTDIR}${EGDIR}/ldapfriendly
	${INSTALL_DATA} ${WRKSRC}/dist/${OPSYS}*/etc/ldaptemplates.conf   ${DESTDIR}${EGDIR}/ldaptemplates.conf

.include "../../mk/bsd.pkg.mk"
