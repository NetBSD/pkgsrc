# $NetBSD: Makefile,v 1.11 2002/04/05 11:49:37 wennmach Exp $
#

DISTNAME=		xdm-krb4-3.3.6.3
CATEGORIES=		security x11
MASTER_SITES=		ftp://gutemine.geo.Uni-Koeln.DE/pub/xdm-krb4/

MAINTAINER=		wennmach@netbsd.org
COMMENT=		Kerberos IV and AFS aware xdm

.if exists(/usr/lib/libroken.a)
KRB4_INCLUDE=		-I/usr/include/kerberosIV
KRB4_LIBS=		-L/usr/lib -lkafs -lkrb -ldes -lkrb5 -lroken -lasn1 -lcom_err
.else
.include "../../security/kth-krb4/buildlink.mk"
USE_BUILDLINK_ONLY=	# defined
KRB4_INCLUDE=		-I${BUILDLINK_DIR}/include/kerberosIV
KRB4_LIBS=		-L${BUILDLINK_DIR}/lib -lkafs -lkrb -ldes
.endif

USE_X11BASE=		yes
USE_IMAKE=		yes

.include "../../mk/bsd.prefs.mk"

post-patch:
	@${SED} -e 's|@KRB4_INCLUDE@|${KRB4_INCLUDE}|g'                       \
	        -e 's|@KRB4_LIBS@|${KRB4_LIBS}|g'                             \
		< ${WRKSRC}/Imakefile.in                                      \
		> ${WRKSRC}/Imakefile

pre-install:
	@${SED} -e 's|@PREFIX@|${PREFIX}|g'                                   \
		${FILESDIR}/xdm_krb4                                          \
		>${WRKDIR}/xdm_krb4   

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/etc/rc.d
	${INSTALL_DATA}                                                       \
		${WRKDIR}/xdm_krb4                                            \
		${PREFIX}/etc/rc.d/xdm_krb4

.include "../../mk/bsd.pkg.mk"
