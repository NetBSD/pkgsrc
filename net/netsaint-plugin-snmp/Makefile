# $NetBSD: Makefile,v 1.3 2001/09/27 23:18:29 jlam Exp $
#

DISTNAME=	netsaint-plugins-1.2.8-4
PKGNAME=	netsaint-plugin-snmp-1.2.8.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=netsaintplug/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://netsaintplug.sourceforge.net/
COMMENT=	SNMP monitoring plug-in for netsaint

DEPENDS+=	netsaint-base-[0-9]*:../../net/netsaint-base
DEPENDS+=	ucd-snmp-[0-9]*:../../net/ucd-snmp

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
