# $NetBSD: Makefile,v 1.1.1.1 2001/01/16 18:11:07 rh Exp $
#

DISTNAME=	netsaint-plugins-1.2.8-4
PKGNAME=	netsaint-plugin-snmp-1.2.8.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=netsaintplug/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://netsaintplug.sourceforge.net/

DEPENDS+=	netsaint-base-*:../../net/netsaint-base
DEPENDS+=	ucd-snmp-*:../../net/ucd-snmp

.include "../../net/netsaint-base/Makefile.common"

ALL_TARGET=	check_snmp

do-build:
	cd ${WRKSRC}/plugins &&						\
	${SETENV} ${MAKE_ENV}						\
	${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${ALL_TARGET}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/${ALL_TARGET}		\
	    ${PREFIX}/libexec/netsaint

.include "../../mk/bsd.pkg.mk"
