# $NetBSD: Makefile,v 1.11 2004/04/24 22:46:11 jlam Exp $

.include "../../net/samba2/Makefile.common"

PKGNAME=		pam-smbpass-${SAMBA_DIST_VERS}
PKGREVISION=		1
CATEGORIES=		security

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		PAM authentication against a Samba password database

CONFLICTS+=		samba>=3.0

DEPENDS+=		{samba>=2.0,ja-samba>=2.0}:../../net/samba

USE_BUILDLINK3=		yes
CONFIGURE_ARGS+=	--with-pam

ALL_TARGET=		pam_smbpass

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}

INSTALL_LIBRARY= \
	${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}

do-install:
	${INSTALL_DATA_DIR} ${PAM_INSTMODULEDIR}
	${INSTALL_LIBRARY} ${WRKSRC}/bin/pam_smbpass.so ${PAM_INSTMODULEDIR}
	${INSTALL_DATA_DIR} ${DOCDIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/pam_smbpass/README ${DOCDIR}
	cd ${WRKSRC}/pam_smbpass/samples; for file in *; do		\
		${INSTALL_DATA} $${file} ${EGDIR}/$${file};		\
	done

.include "../../security/PAM/module.mk"
.include "../../mk/bsd.pkg.mk"
