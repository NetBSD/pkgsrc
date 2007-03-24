# $NetBSD: Makefile,v 1.2 2007/03/24 19:21:31 joerg Exp $

DISTNAME=	pam-pwauth_suid-1.0
CATEGORIES=	security
DISTFILES=	# empty

MAINTAINER=	drochner@NetBSD.org
COMMENT=	PAM authentication module for unprivileged users

NO_CHECKSUM=	yes
WRKSRC=		${WRKDIR}
CFLAGS+=	-DPATH_HELPER=\"${PREFIX}/libexec/pwauth_suid_helper\"

INSTALLATION_DIRS=	lib/security libexec

do-extract:
	${CP} ${FILESDIR}/pam_pwauth_suid.c ${FILESDIR}/pwauth_suid_helper.c \
		${WRKSRC}

do-build:
	(cd ${WRKSRC} && \
	 ${CC} ${CFLAGS} -shared pam_pwauth_suid.c -o pam_pwauth_suid.so.0 && \
	 ${CC} ${CFLAGS} pwauth_suid_helper.c -o pwauth_suid_helper -lcrypt)

do-install:
	${INSTALL_DATA} ${WRKSRC}/pam_pwauth_suid.so.0 ${PREFIX}/lib/security
	${INSTALL_PROGRAM} ${WRKSRC}/pwauth_suid_helper ${PREFIX}/libexec
	${CHMOD} 04555 ${PREFIX}/libexec/pwauth_suid_helper

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
