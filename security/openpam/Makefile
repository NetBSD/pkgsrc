# $NetBSD: Makefile,v 1.33 2020/03/18 12:20:45 tnn Exp $

DISTNAME=	openpam-20190224
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openpam/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://www.openpam.org/
COMMENT=	Open-source PAM library
LICENSE=	modified-bsd

CONFLICTS+=	PAM-[0-9]*

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-pam-unix
CONFIGURE_ARGS+=	--with-modules-dir=${PREFIX}/lib/security

CPPFLAGS+=		-DSYSCONFDIR=\"${PKG_SYSCONFDIR}\"

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES+=		${EGDIR}/pam.d/other ${PKG_SYSCONFDIR}/pam.d/other
CONF_FILES+=		${EGDIR}/pam.d/sudo ${PKG_SYSCONFDIR}/pam.d/sudo

OWN_DIRS=		${PKG_SYSCONFDIR}/pam.d
INSTALLATION_DIRS+=	${EGDIR}/pam.d

SUBST_CLASSES+=		man
SUBST_MESSAGE.man=	Fixing hardcoded paths in manpages.
SUBST_STAGE.man=	post-build
SUBST_FILES.man=	doc/man/pam.conf.5
SUBST_VARS.man=		PKG_SYSCONFDIR PREFIX

post-extract:
	${MKDIR} -p ${WRKSRC}/doc/pam.d
	${CP} ${FILESDIR}/other ${WRKSRC}/doc/pam.d/other
	${CP} ${FILESDIR}/sudo ${WRKSRC}/doc/pam.d/sudo

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/pam.d/other ${DESTDIR}${EGDIR}/pam.d/other
	${INSTALL_DATA} ${WRKSRC}/doc/pam.d/sudo ${DESTDIR}${EGDIR}/pam.d/sudo

.include "../../mk/dlopen.buildlink3.mk"

# Create a fake perl binary to avoid recreating the man pages.
post-tools:
	${RM} -f ${TOOLS_DIR}/bin/perl
	${ECHO} "#!${TOOLS_SHELL}" > ${TOOLS_DIR}/bin/perl
	${ECHO} "${TRUE}" >> ${TOOLS_DIR}/bin/perl
	${CHMOD} +x ${TOOLS_DIR}/bin/perl

.include "../../mk/bsd.pkg.mk"
