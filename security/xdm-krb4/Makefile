# $NetBSD: Makefile,v 1.17 2004/10/03 00:18:14 tv Exp $
#

DISTNAME=		xdm-krb4-3.3.6.3
PKGREVISION=		2
CATEGORIES=		security x11
MASTER_SITES=		ftp://gutemine.geo.Uni-Koeln.DE/pub/xdm-krb4/

MAINTAINER=		wennmach@NetBSD.org
COMMENT=		Kerberos IV and AFS aware xdm

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
USE_IMAKE=		yes

.if exists(/usr/lib/libroken.a)
KRB4_INCLUDE=	-I/usr/include/kerberosIV
KRB4_LIBS=	-L/usr/lib -lkafs -lkrb -ldes -lkrb5 -lroken -lasn1 -lcom_err
.else
.  include "../../security/kth-krb4/buildlink3.mk"
KRB4_INCLUDE=	-I${BUILDLINK_PREFIX.kth-krb4}/include/kerberosIV
KRB4_LIBS=	-L${BUILDLINK_PREFIX.kth-krb4}/lib -lkafs -lkrb -ldes
.endif

MAKE_ENV+=	XDM_EXAMPLEDIR="${EXAMPLEDIR}"

XDM_CONFDIR=	${PREFIX}/lib/X11/xdm
EXAMPLEDIR=	${PREFIX}/share/examples/${PKGBASE}
CFILES=		GiveConsole TakeConsole
CFILES+=	Xaccess Xresources Xservers Xsession Xsetup_0
CFILES+=	xdm-config
.for FILE in ${CFILES}
CONF_FILES+=	${EXAMPLEDIR}/${FILE} ${XDM_CONFDIR}/${FILE}
.endfor

RCD_SCRIPTS=	xdm_krb4

post-patch:
	@${SED} -e 's|@KRB4_INCLUDE@|${KRB4_INCLUDE}|g'			\
	        -e 's|@KRB4_LIBS@|${KRB4_LIBS}|g'			\
		${WRKSRC}/Imakefile.in > ${WRKSRC}/Imakefile

pre-install:
	${INSTALL_DATA_DIR} ${EXAMPLEDIR}

.include "../../mk/bsd.pkg.mk"
