# $NetBSD: Makefile,v 1.8 1999/07/13 01:20:14 jlam Exp $
# FreeBSD Id: Makefile,v 1.9 1997/03/08 05:00:11 gpalmer Exp
#

DISTNAME=		amanda-2.4.1p1
PKGNAME=		amanda-server-2.4.1p1
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.cs.umd.edu/pub/amanda/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.amanda.org/

DEPENDS+=		readline-4.0:../../devel/readline
DEPENDS+=		gnuplot-3.7:../../graphics/gnuplot
DEPENDS+=		amanda-common-2.4.1p1:../amanda-common

USE_X11=		yes
USE_PERL5=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
AMANDA_GROUP=		operator
.elif ${OPSYS} == "SunOS"
AMANDA_GROUP=		sysadmin
.endif

AMANDA_USER?=		backup
AMANDA_VAR?=		/var/amanda

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-user=${AMANDA_USER} \
			--with-group=${AMANDA_GROUP} \
			--with-owner=root \
			--with-mmap --with-amandahosts \
			--with-includes=${PREFIX}/include \
			--with-libraries=${PREFIX}/lib \
			--localstatedir=${AMANDA_VAR} \
			--with-gnutar-listdir=${AMANDA_VAR}/gnutar-lists \
			--with-dump-honor-nodump \
			--without-client

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
