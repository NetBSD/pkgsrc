# $NetBSD: Makefile,v 1.14 2004/08/07 08:18:38 jdolecek Exp $

PKGNAME=		winbind-${SAMBA_DIST_VERS}
PKGREVISION=		# empty
CATEGORIES=		security

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes

.include "../../net/samba2/Makefile.common"

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.samba.org/
COMMENT=		Unified logon information between UNIX and Windows NT

CONFLICTS+=		samba>=3.0

DEPENDS+=		{samba>=2.0,ja-samba>=2.0}:../../net/samba2

CONFIGURE_ARGS+=	--with-ssl
CONFIGURE_ARGS+=	--with-sslinc=${BUILDLINK_PREFIX.openssl}
CFLAGS+=		-I${BUILDLINK_PREFIX.openssl}/include/openssl	# ssl.h, err.h

CONFIGURE_ARGS+=	--with-pam
CONFIGURE_ARGS+=	--with-winbind

ALL_TARGET=		nsswitch

RCD_SCRIPTS=		winbindd

INSTALLATION_DIRS=	bin lib sbin
INSTALL_LIBRARY= \
	${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}

# The man pages remain with the samba package.
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/wbinfo ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/winbindd ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${PAM_INSTMODULEDIR}
	${INSTALL_LIBRARY} ${WRKSRC}/nsswitch/pam_winbind.so ${PAM_INSTMODULEDIR}
	${INSTALL_LIBRARY} ${WRKSRC}/nsswitch/libnss_winbind.so ${PREFIX}/lib

.include "../../security/PAM/module.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
