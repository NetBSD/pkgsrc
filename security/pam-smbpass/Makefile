# $NetBSD: Makefile,v 1.5 2003/07/17 22:53:09 grant Exp $

.include "../../net/samba/Makefile.common"

PKGNAME=		pam-smbpass-${SAMBA_DIST_VERS}
CATEGORIES=		security

MAINTAINER=		jlam@NetBSD.org
COMMENT=		PAM authentication against a Samba password database

DEPENDS+=		{samba>=2.0,ja-samba>=2.0}:../../net/samba

USE_BUILDLINK2=		# defined
CONFIGURE_ARGS+=	--with-pam

ALL_TARGET=		pam_smbpass

PAMDIR=			${PREFIX}/lib/security
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}

INSTALL_LIBRARY= \
	${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}

do-install:
	${INSTALL_LIBRARY} ${WRKSRC}/bin/pam_smbpass.so ${PAMDIR}
	${INSTALL_DATA_DIR} ${DOCDIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/pam_smbpass/README ${DOCDIR}
	cd ${WRKSRC}/pam_smbpass/samples; for file in *; do		\
		${INSTALL_DATA} $${file} ${EGDIR}/$${file};		\
	done

.include "../../security/PAM/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
