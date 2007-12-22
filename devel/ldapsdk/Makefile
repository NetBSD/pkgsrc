# $NetBSD: Makefile,v 1.27 2007/12/22 07:22:07 obache Exp $

DISTNAME=	ldapsdk_12311998
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	2
CATEGORIES=	devel databases
MASTER_SITES=	${MASTER_SITE_MOZILLA_ALL:=directory/c-sdk/ancient/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mozilla.org/directory/
COMMENT=	LDAP C-SDK from the Mozilla project

CONFLICTS+=	openldap-client-[0-9]*

WRKSRC=		${WRKDIR}/mozilla
USE_TOOLS+=	gmake perl

PKG_SYSCONFSUBDIR=	ldapsdk
EGDIR=			${PREFIX}/share/examples/ldapsdk

MAKE_ENV+=	MOZILLA_CLIENT=1
MAKE_ENV+=	NO_MDUPDATE=1
MAKE_ENV+=	MOZ_LDAP_SDK=1
MAKE_FILE=	directory/ldapsdk.mk
BUILD_TARGET=	build

INSTALLATION_DIRS_FROM_PLIST=	yes

post-extract:
	${LN} -s FreeBSD.mk ${WRKSRC}/config/DragonFly.mk

do-configure:
	${ECHO} "PKG_SYSCONFDIR=${PKG_SYSCONFDIR}" >> ${WRKSRC}/config/rules.mk
	${ECHO} "EGDIR=${EGDIR}" >> ${WRKSRC}/config/rules.mk

do-install:
	cd ${WRKSRC}/dist/public/ldap \
	&& ${INSTALL_DATA} disptmpl.h lber.h ldap.h srchpref.h ${PREFIX}/include
	#
	# XXX kludge
	#
	${INSTALL_DATA} ${WRKSRC}/dist/${OPSYS}*/lib/libldap.a ${PREFIX}/lib/libldap.a
	${INSTALL_DATA} ${WRKSRC}/dist/${OPSYS}*/lib/liblber.a ${PREFIX}/lib/liblber.a
	${INSTALL_LIB} ${WRKSRC}/dist/${OPSYS}*/bin/libldap.so.1.0 ${PREFIX}/lib/libldap.so.1.0
	${LN} -sf libldap.so.1.0 ${PREFIX}/lib/libldap.so.1
	${LN} -sf libldap.so.1.0 ${PREFIX}/lib/libldap.so
	${INSTALL_LIB} ${WRKSRC}/dist/${OPSYS}*/bin/liblber.so.1.0 ${PREFIX}/lib/liblber.so.1.0
	${LN} -sf liblber.so.1.0 ${PREFIX}/lib/liblber.so.1
	${LN} -sf liblber.so.1.0 ${PREFIX}/lib/liblber.so
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/${OPSYS}*/etc/ldapfilter.conf      ${EGDIR}/ldapfilter.conf
	${INSTALL_DATA} ${WRKSRC}/dist/${OPSYS}*/etc/ldapsearchprefs.conf ${EGDIR}/ldapsearchprefs.conf
	${INSTALL_DATA} ${WRKSRC}/dist/${OPSYS}*/etc/ldapfriendly         ${EGDIR}/ldapfriendly
	${INSTALL_DATA} ${WRKSRC}/dist/${OPSYS}*/etc/ldaptemplates.conf   ${EGDIR}/ldaptemplates.conf

.include "../../mk/bsd.pkg.mk"
