# $NetBSD: Makefile,v 1.12 1999/09/06 19:30:21 bad Exp $
# FreeBSD Id: Makefile,v 1.9 1997/03/08 05:00:11 gpalmer Exp
#

DISTNAME=		amanda-2.4.1p1
PKGNAME=		amanda-server-2.4.1p1
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.cs.umd.edu/pub/amanda/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.amanda.org/

DEPENDS+=		readline-4.0:../../devel/readline
DEPENDS+=		amanda-common-2.4.1p1:../../sysutils/amanda-common

USE_X11=		yes
USE_PERL5=		yes

.include "../../mk/bsd.prefs.mk"
.include "../../sysutils/amanda-common/Makefile.common"

CONFIGURE_ARGS+=	--without-client

BUILD_DEFS+=		AMANDA_USER AMANDA_SMB AMANDA_VAR

post-install:
	${MKDIR} ${PREFIX}/share/doc/amanda
	${MKDIR} ${PREFIX}/share/examples/amanda
	for i in ${WRKDIR}/${DISTNAME}/docs/* ; do \
		${INSTALL_DATA} $$i ${PREFIX}/share/doc/amanda; \
	done
	for i in ${WRKDIR}/${DISTNAME}/example/8.5x11.ps \
	    ${WRKDIR}/${DISTNAME}/example/DIN-A4.ps \
	    ${WRKDIR}/${DISTNAME}/example/DLT.ps \
	    ${WRKDIR}/${DISTNAME}/example/EXB-8500.ps \
	    ${WRKDIR}/${DISTNAME}/example/HP-DAT.ps \
	    ${WRKDIR}/${DISTNAME}/example/amanda.conf \
	    ${WRKDIR}/${DISTNAME}/example/chg-multi.conf \
	    ${WRKDIR}/${DISTNAME}/example/chg-scsi.conf \
	    ${WRKDIR}/${DISTNAME}/example/config.site \
	    ${WRKDIR}/${DISTNAME}/example/disklist; do \
		${INSTALL_DATA} $$i ${PREFIX}/share/examples/amanda; \
	done

.include "../../mk/bsd.pkg.mk"
