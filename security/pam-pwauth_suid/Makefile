# $NetBSD: Makefile,v 1.12 2020/10/23 09:20:59 tnn Exp $

DISTNAME=	pam-pwauth_suid-1.2
PKGREVISION=	1
CATEGORIES=	security
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	PAM authentication module for unprivileged users

WRKSRC=		${WRKDIR}

PAMDEF+=	-DPATH_HELPER=\"${PREFIX}/libexec/pwauth_suid_helper\"

INSTALLATION_DIRS=	lib/security libexec share/examples/pam-pwauth_suid

do-extract:
	${CP} ${FILESDIR}/pam_pwauth_suid.c ${FILESDIR}/pwauth_suid_helper.c \
		${WRKSRC}

do-build:
	(cd ${WRKSRC} && \
	 ${CC} ${CFLAGS} -c -fPIC ${PAMDEF} pam_pwauth_suid.c && \
	 ${CC} ${LDFLAGS} -shared pam_pwauth_suid.o -o pam_pwauth_suid.so && \
	 ${CC} ${CFLAGS} ${LDFLAGS} pwauth_suid_helper.c -o pwauth_suid_helper -lcrypt)

do-install:
	${INSTALL_LIB} ${WRKSRC}/pam_pwauth_suid.so \
		${DESTDIR}${PREFIX}/lib/security
	${INSTALL_PROGRAM} ${WRKSRC}/pwauth_suid_helper \
		${DESTDIR}${PREFIX}/libexec
	${CHMOD} 04555 ${DESTDIR}${PREFIX}/libexec/pwauth_suid_helper
	${SED} -e 's|@PREFIX@|${PREFIX}|g' ${FILESDIR}/xscreensaver > \
		${DESTDIR}${PREFIX}/share/examples/pam-pwauth_suid/xscreensaver

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
