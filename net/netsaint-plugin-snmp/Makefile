# $NetBSD: Makefile,v 1.8 2002/04/20 18:46:07 fredb Exp $
#

DISTNAME=	netsaint-plugins-1.2.9-4
PKGNAME=	netsaint-plugin-snmp-1.2.9.4
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=netsaintplug/}

MAINTAINER=	murray@river-styx.org
HOMEPAGE=	http://netsaintplug.sourceforge.net/
COMMENT=	SNMP monitoring plug-in for netsaint

DEPENDS+=	autoconf>=2.13:../../devel/autoconf
DEPENDS+=	automake>=1.4.5:../../devel/automake
DEPENDS+=	netsaint-base-[0-9]*:../../net/netsaint-base
DEPENDS+=	ucd-snmp-4.2.4*:../../net/ucd-snmp

.include "../../net/netsaint-base/Makefile.common"

ALL_TARGET=	check_snmp check_hpjd

pre-configure:
	cd ${WRKSRC};	\
	${LOCALBASE}/bin/aclocal;	\
	${LOCALBASE}/bin/autoheader;	\
	${LOCALBASE}/bin/automake -a --foreign -i;	\
	${LOCALBASE}/bin/autoconf

do-build:
	cd ${WRKSRC}/plugins &&		\
	${SETENV} ${MAKE_ENV}		\
	${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${ALL_TARGET}

do-install:
	for PROG in ${ALL_TARGET}; do	\
		${INSTALL_PROGRAM} ${WRKSRC}/plugins/$${PROG}	\
		${PREFIX}/libexec/netsaint;	\
	done

.include "../../mk/bsd.pkg.mk"
