# $NetBSD: Makefile,v 1.2 2005/01/13 21:54:22 jlam Exp $

DISTNAME=	openpam-20040210
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

.include "../../mk/dlopen.buildlink3.mk"

# Create a fake perl binary to avoid recreating the man pages.
post-tools:
	${RM} -f ${TOOLS_DIR}/bin/perl
	${LN} -sf ${TRUE} ${TOOLS_DIR}/bin/perl

# Remove a directory that's created for the sample su application that
# we don't install.
#
post-install:
	${RMDIR} -p ${PREFIX}/bin 2>/dev/null || ${TRUE}

.include "../../mk/bsd.pkg.mk"
