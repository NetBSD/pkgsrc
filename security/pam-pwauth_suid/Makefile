# $NetBSD: Makefile,v 1.3 2007/09/05 20:29:05 drochner Exp $

DISTNAME=	pam-pwauth_suid-1.1
CATEGORIES=	security
DISTFILES=	# empty

MAINTAINER=	drochner@NetBSD.org
COMMENT=	PAM authentication module for unprivileged users

NO_CHECKSUM=	yes
WRKSRC=		${WRKDIR}

HLPDEF+= -DPATH_HELPER=\"${DESTDIR}${PREFIX}/libexec/pwauth_suid_helper\"

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	lib/security libexec

do-extract:
	${CP} ${FILESDIR}/pam_pwauth_suid.c ${FILESDIR}/pwauth_suid_helper.c \
		${WRKSRC}

do-build:
	(cd ${WRKSRC} && \
	 ${CC} ${CFLAGS} -c -fPIC ${HLPDEF} pam_pwauth_suid.c && \
	 ${LD} -shared pam_pwauth_suid.o -o pam_pwauth_suid.so.0 && \
	 ${CC} ${CFLAGS} pwauth_suid_helper.c -o pwauth_suid_helper -lcrypt)

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/security
	${INSTALL_DATA} ${WRKSRC}/pam_pwauth_suid.so.0 \
		${DESTDIR}${PREFIX}/lib/security
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/pwauth_suid_helper \
		${DESTDIR}${PREFIX}/libexec
	${CHMOD} 04555 ${DESTDIR}${PREFIX}/libexec/pwauth_suid_helper

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
