# $NetBSD: Makefile,v 1.2 2002/06/25 15:39:31 taca Exp $

DISTNAME=	samba-2.2.2
#
# The pam-smbpass version number is found in the README file within the
# Samba sources.
#
PKGNAME=	pam-smbpass-0.7.5
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.samba.org/pub/samba/ \
		ftp://ring.asahi-net.or.jp/pub/net/samba/ \
		ftp://samba.anu.edu.au/pub/samba/ \
		ftp://de.samba.org/pub/mirror/samba/ \
		ftp://se.samba.org/pub/samba/ \
		ftp://ftp.sunet.se/pub/unix/utilities/samba/

MAINTAINER=	jlam@netbsd.org
COMMENT=	PAM authentication against a Samba password database

DEPENDS+=	{samba>=2.0,ja-samba>=2.0}:../../net/samba

USE_BUILDLINK_ONLY=	yes
WRKSRC=			${WRKDIR}/${DISTNAME}/source

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

SAMBA_ETCDIR?=		${PKG_SYSCONFDIR}/samba
SAMBA_PRIVATE?=		${SAMBA_ETCDIR}/private

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-configdir=${SAMBA_ETCDIR}
CONFIGURE_ARGS+=	--with-privatedir=${SAMBA_PRIVATE}
CONFIGURE_ARGS+=	--with-pam_smbpass
CONFIGURE_ENV+=		ac_cv_lib_curses_tgetent=no

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

.include "../../security/PAM/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
