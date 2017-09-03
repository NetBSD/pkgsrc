# $NetBSD: Makefile,v 1.25 2017/09/03 08:53:14 wiz Exp $

DISTNAME=	openpam-20140912
PKGREVISION=	2
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
CONFIGURE_ARGS+=	--without-pam-su
CONFIGURE_ARGS+=	--with-pam-unix
CONFIGURE_ARGS+=	--with-modules-dir=${PREFIX}/lib/security

CPPFLAGS+=		-DSYSCONFDIR=\"$(PKG_SYSCONFDIR)\"

OWN_DIRS=		${PKG_SYSCONFDIR}/pam.d

.include "../../mk/dlopen.buildlink3.mk"

# Create a fake perl binary to avoid recreating the man pages.
post-tools:
	${RM} -f ${TOOLS_DIR}/bin/perl
	${ECHO} "#!${TOOLS_SHELL}" > ${TOOLS_DIR}/bin/perl
	${ECHO} "${TRUE}" >> ${TOOLS_DIR}/bin/perl
	${CHMOD} +x ${TOOLS_DIR}/bin/perl

.include "../../mk/bsd.pkg.mk"
