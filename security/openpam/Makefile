# $NetBSD: Makefile,v 1.28 2018/08/22 09:46:19 wiz Exp $

DISTNAME=	openpam-20170430
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openpam/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://www.openpam.org/
COMMENT=	Open-source PAM library
LICENSE=	modified-bsd

CONFLICTS+=	PAM-[0-9]*

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-pam-unix
CONFIGURE_ARGS+=	--with-modules-dir=${PREFIX}/lib/security

CPPFLAGS+=		-DSYSCONFDIR=\"${PKG_SYSCONFDIR}\"

OWN_DIRS=		${PKG_SYSCONFDIR}/pam.d

SUBST_CLASSES+=		man
SUBST_MESSAGE.man=	Fixing hardcoded paths in manpages.
SUBST_STAGE.man=	post-build
SUBST_FILES.man=	doc/man/pam.conf.5
SUBST_VARS.man=		PKG_SYSCONFDIR PREFIX

.include "../../mk/dlopen.buildlink3.mk"

# Create a fake perl binary to avoid recreating the man pages.
post-tools:
	${RM} -f ${TOOLS_DIR}/bin/perl
	${ECHO} "#!${TOOLS_SHELL}" > ${TOOLS_DIR}/bin/perl
	${ECHO} "${TRUE}" >> ${TOOLS_DIR}/bin/perl
	${CHMOD} +x ${TOOLS_DIR}/bin/perl

.include "../../mk/bsd.pkg.mk"
