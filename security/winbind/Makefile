# $NetBSD: Makefile,v 1.3 2002/09/19 09:04:26 jlam Exp $

PKGNAME=		winbind-${SAMBA_DIST_VERS}
CATEGORIES=		security

USE_BUILDLINK_ONLY=	# defined

.include "../../net/samba/Makefile.common"

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.samba.org/
COMMENT=		unified logon information between UNIX and Windows NT

DEPENDS+=		{samba>=2.0,ja-samba>=2.0}:../../net/samba

CONFIGURE_ARGS+=	--with-ssl
CONFIGURE_ARGS+=	--with-sslinc=${BUILDLINK_DIR}
CFLAGS+=		-I${BUILDLINK_DIR}/include/openssl	# ssl.h, err.h

CONFIGURE_ARGS+=	--with-pam
CONFIGURE_ARGS+=	--with-winbind

ALL_TARGET=		nsswitch

PAMDIR=			${PREFIX}/lib/security
RCD_SCRIPTS=		winbindd

INSTALL_LIBRARY= \
	${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}

# The man pages remain with the samba package.
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/wbinfo ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/winbindd ${PREFIX}/sbin
	${INSTALL_LIBRARY} ${WRKSRC}/nsswitch/pam_winbind.so ${PAMDIR}
	${INSTALL_LIBRARY} ${WRKSRC}/nsswitch/libnss_winbind.so ${PREFIX}/lib

.include "../../security/PAM/buildlink.mk"
.include "../../security/openssl/buildlink.mk"

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
