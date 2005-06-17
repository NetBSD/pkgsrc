# $NetBSD: Makefile,v 1.13 2005/06/17 03:50:26 jlam Exp $
#

DISTNAME=	netsaint-plugins-1.2.9-4
PKGNAME=	netsaint-plugin-snmp-1.2.9.4
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=netsaintplug/}

MAINTAINER=	murray@river-styx.org
HOMEPAGE=	http://netsaintplug.sourceforge.net/
COMMENT=	SNMP monitoring plug-in for netsaint

DEPENDS+=	netsaint-base-[0-9]*:../../net/netsaint-base
DEPENDS+=	net-snmp>=5.0.9:../../net/net-snmp

.include "../../net/netsaint-base/Makefile.common"

BUILD_TARGET=	check_snmp check_hpjd

INSTALLATION_DIRS=	libexec/netsaint

do-build:
	cd ${WRKSRC}/plugins &&		\
	${SETENV} ${MAKE_ENV}		\
	${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${BUILD_TARGET}

do-install:
	for PROG in ${BUILD_TARGET}; do	\
		${INSTALL_PROGRAM} ${WRKSRC}/plugins/$${PROG}	\
		${PREFIX}/libexec/netsaint;	\
	done

.include "../../mk/bsd.pkg.mk"
