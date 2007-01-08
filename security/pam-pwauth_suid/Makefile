# $NetBSD: Makefile,v 1.1.1.1 2007/01/08 18:39:44 drochner Exp $

DISTNAME=	pam-pwauth_suid-1.0
CATEGORIES=	security
DISTFILES=	# empty

MAINTAINER=	drochner@NetBSD.org
COMMENT=	PAM authentication module for unprivileged users

NO_CHECKSUM=	yes
WRKSRC=		${WRKDIR}
CFLAGS+=	-DPATH_HELPER=\"${PREFIX}/libexec/pwauth_suid_helper\"

do-extract:
	${CP} ${FILESDIR}/pam_pwauth_suid.c ${FILESDIR}/pwauth_suid_helper.c \
		${WRKSRC}

do-build:
	(cd ${WRKSRC} && \
	 ${CC} ${CFLAGS} -shared pam_pwauth_suid.c -o pam_pwauth_suid.so.0 && \
	 ${CC} ${CFLAGS} pwauth_suid_helper.c -o pwauth_suid_helper -lcrypt)

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/security
	${INSTALL_DATA} ${WRKSRC}/pam_pwauth_suid.so.0 ${PREFIX}/lib/security
	${INSTALL_PROGRAM} ${WRKSRC}/pwauth_suid_helper ${PREFIX}/libexec
	${CHMOD} 04555 ${PREFIX}/libexec/pwauth_suid_helper

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
