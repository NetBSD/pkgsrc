# $NetBSD: Makefile,v 1.6 2005/02/10 02:55:39 jlam Exp $

DISTNAME=	openpam-20050201
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openpam/}

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://www.openpam.org/
COMMENT=	open-source PAM library

CONFLICTS+=	PAM-[0-9]*

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--without-pam-su
CONFIGURE_ARGS+=	--with-pam-unix
CONFIGURE_ARGS+=	--with-modules-dir=${PREFIX}/lib/security

USE_PKGINSTALL=		yes
OWN_DIRS=		${PKG_SYSCONFDIR}/pam.d

.include "../../mk/dlopen.buildlink3.mk"

# Create a fake perl binary to avoid recreating the man pages.
post-tools:
	${RM} -f ${TOOLS_DIR}/bin/perl
	${ECHO} "#!${TOOLS_SHELL}" > ${TOOLS_DIR}/bin/perl
	${ECHO} "${TRUE}" >> ${TOOLS_DIR}/bin/perl
	${CHMOD} +x ${TOOLS_DIR}/bin/perl

# Remove a directory that's created for the sample su application that
# we don't install.
#
post-install:
	${RMDIR} -p ${PREFIX}/bin 2>/dev/null || ${TRUE}

.include "../../mk/bsd.pkg.mk"
