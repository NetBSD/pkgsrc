# $NetBSD: Makefile,v 1.26 2001/02/17 18:25:03 wiz Exp $
#

DISTNAME=		qpopper3.1.2
PKGNAME=		qpopper-3.1.2
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.qualcomm.com/eudora/servers/unix/popper/

PATCH_SITES=		http://www.imasy.or.jp/~ume/ipv6/
PATCHFILES=		qpopper3.1.2-ipv6-20001214.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=		mellon@fugue.com
HOMEPAGE=		http://eudora.qualcomm.com/freeware/qpop.html
COMMENT=		Qualcomm's POP server for Eudora

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/libexec \
			--sysconfdir=${PREFIX}/etc --enable-apop \
			--with-apop=/etc/apop.auth --with-apopuid=root

.include "../../mk/bsd.prefs.mk"

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
	 ${INSTALL_PROGRAM} popper/popper ${PREFIX}/libexec/qpopper; \
	 ${INSTALL} -o root -c -g ${BINGRP} -m 4755 popper/popauth \
		${PREFIX}/bin/qpopauth; \
	 ${INSTALL_MAN} man/popper.8 ${PREFIX}/man/man8/qpopper.8; \
	 ${INSTALL_MAN} man/popauth.8 ${PREFIX}/man/man8/qpopauth.8 ; \
	 ${INSTALL_MAN} License.txt ${PREFIX}/share/doc/qpopper.License \
	)

.include "../../mk/bsd.pkg.mk"
