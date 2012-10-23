# $NetBSD: Makefile,v 1.7 2012/10/23 18:16:48 asau Exp $

DISTNAME=	pam-pwauth_suid-1.2
CATEGORIES=	security
DISTFILES=	# empty

MAINTAINER=	drochner@NetBSD.org
COMMENT=	PAM authentication module for unprivileged users

WRKSRC=		${WRKDIR}

PAMDEF+= -DPATH_HELPER=\"${PREFIX}/libexec/pwauth_suid_helper\"
PAMDEF+= -DNO_STATIC_MODULES

INSTALLATION_DIRS=	lib/security libexec share/examples/pam-pwauth_suid

do-extract:
	${CP} ${FILESDIR}/pam_pwauth_suid.c ${FILESDIR}/pwauth_suid_helper.c \
		${WRKSRC}

do-build:
	(cd ${WRKSRC} && \
	 ${CC} ${CFLAGS} -c -fPIC ${PAMDEF} pam_pwauth_suid.c && \
	 ${LD} -shared pam_pwauth_suid.o -o pam_pwauth_suid.so && \
	 ${CC} ${CFLAGS} pwauth_suid_helper.c -o pwauth_suid_helper -lcrypt)

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/security
	${INSTALL_DATA} ${WRKSRC}/pam_pwauth_suid.so \
		${DESTDIR}${PREFIX}/lib/security
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/pwauth_suid_helper \
		${DESTDIR}${PREFIX}/libexec
	${CHMOD} 04555 ${DESTDIR}${PREFIX}/libexec/pwauth_suid_helper
	sed -e 's|@PREFIX@|${PREFIX}|g' ${FILESDIR}/xscreensaver > \
		${DESTDIR}${PREFIX}/share/examples/pam-pwauth_suid/xscreensaver

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
