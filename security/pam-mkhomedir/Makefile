# $NetBSD: Makefile,v 1.5 2012/10/23 18:16:48 asau Exp $

DISTNAME=	pam-mkhomedir-1
CATEGORIES=	security
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tonnerre@NetBSD.org
COMMENT=	Pluggable authentication module for automatic homedir creation

INSTALLATION_DIRS=	lib/security
LDLIBS=			-lpam

USE_LIBTOOL=		yes

WRKSRC=			${WRKDIR}

do-extract:
	${CP} ${FILESDIR}/pam_mkhomedir.c ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${SHLIBTOOL} --mode=compile ${CC} ${CFLAGS}	\
		-c pam_mkhomedir.c
	cd ${WRKSRC} && ${SHLIBTOOL} --mode=link ${CC} ${LDFLAGS}	\
		-avoid-version -module ${LDLIBS} -o pam_mkhomedir.la	\
		-rpath ${PREFIX}/lib/security pam_mkhomedir.lo

do-install:
	${SHLIBTOOL} --mode=install ${INSTALL_PROGRAM} -c		\
		${WRKSRC}/pam_mkhomedir.la ${DESTDIR}${PREFIX}/lib/security

# Fix (workaround?) a bug with openpam/NetBSD
# The bug is described in PR security/39313.
#
.include "../../mk/bsd.prefs.mk"
#
.if ${OPSYS} == "NetBSD"
CFLAGS+=		-DNO_STATIC_MODULES
.endif

.include "../../mk/pam.buildlink3.mk"
.if "${PAM_TYPE}" == "linux-pam"
PKG_FAIL_REASON+= "Disabled: The PAM mkhomedir module is included in the PAM package."
.endif
.include "../../mk/bsd.pkg.mk"
