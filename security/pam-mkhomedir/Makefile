# $NetBSD: Makefile,v 1.7 2016/02/26 09:41:06 jperkin Exp $

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
CFLAGS.NetBSD+=		-DNO_STATIC_MODULES

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
