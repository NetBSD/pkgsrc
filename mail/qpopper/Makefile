# $NetBSD: Makefile,v 1.21 2000/08/18 20:37:28 hubertf Exp $
#

DISTNAME=		qpopper2.53
PKGNAME=		qpopper-2.53
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.qualcomm.com/eudora/servers/unix/popper/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		mellon@fugue.com
HOMEPAGE=		http://eudora.qualcomm.com/freeware/qpop.html

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/libexec \
			--sysconfdir=${PREFIX}/etc --enable-apop \
			--with-apop=/etc/apop.auth --with-apopuid=root

.include "../../mk/bsd.prefs.mk"

.if defined(USE_KERBEROS4)
CONFIGURE_ARGS+=--enable-kerberos
RESTRICTED=     uses Kerberos encryption code
.endif

BUILD_DEFS+=		QPOPPER_SERVERMODE USE_INET6

.include "../../mk/bsd.prefs.mk"

.if defined(QPOPPER_SERVERMODE)
CONFIGURE_ARGS+=	--enable-servermode
.endif
.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ENV+=		O_DEFS="${O_DEFS}" CFLAGS="-DINET6"
.endif

# popper makefile doesn't have an install target...
do-install:
	(cd ${WRKSRC}; \
	 ${INSTALL_PROGRAM} popper	${PREFIX}/libexec/qpopper; \
	 ${INSTALL_MAN} popper.8	${PREFIX}/man/man8/qpopper.8; \
	 ${INSTALL_MAN} popauth.8	${PREFIX}/man/man8/qpopauth.8 ; \
	 ${INSTALL_MAN} License		${PREFIX}/share/doc/qpopper.License \
	)

.include "../../mk/bsd.pkg.mk"
