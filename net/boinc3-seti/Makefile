# $NetBSD: Makefile,v 1.2 2004/10/03 00:17:49 tv Exp $
#

DISTNAME=		seti_boinc-client-cvs-2004-07-15
PKGNAME=		boinc3-seti-20040715
PKGREVISION=	1
CATEGORIES=		net
MASTER_SITES=		http://boinc.berkeley.edu/seti_source/nightly/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://setiweb.ssl.berkeley.edu/
COMMENT=		SETI@home client for the BOINC framework

WRKSRC=		${WRKDIR}/seti_boinc
USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		BOINCDIR=${BUILDLINK_DIR}/boinc3
# XXX don't know why MySQL is needed here
#CONFIGURE_ENV+=		MYSQL_CONFIG=true
USE_GNU_TOOLS+=		make

CLIENTBINNAME=	setiathome-3.10.${MACHINE_GNU_PLATFORM}
CLIENTVERSION=	310

PLIST_SUBST+=	CLIENTBINNAME=${CLIENTBINNAME}
APPINFO_SED=	-e "s|@CLIENTBINNAME@|${CLIENTBINNAME}|g"
APPINFO_SED+=	-e "s|@CLIENTVERSION@|${CLIENTVERSION}|g"

# XXX hack: boinc-lib detection code is too stupid...
pre-configure:
	${TOUCH} ${BUILDLINK_DIR}/boinc3/Makefile.am

SBDIR=	${PREFIX}/lib/boinc3-seti

do-install:
	${INSTALL_DATA_DIR} ${SBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/client/${CLIENTBINNAME} ${SBDIR}
	${SED} ${APPINFO_SED} <${FILESDIR}/app_info.xml \
		>${WRKDIR}/app_info.xml
	${INSTALL_DATA} ${WRKDIR}/app_info.xml ${SBDIR}

.include "../../net/boinc3-libs/buildlink3.mk"
.include "../../databases/mysql-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
