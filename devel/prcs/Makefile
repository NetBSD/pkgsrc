# $NetBSD: Makefile,v 1.35 2005/06/24 17:53:22 kristerw Exp $

DISTNAME= 		prcs-1.3.3
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=prcs/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://prcs.sourceforge.net/
COMMENT=		Project Revision Control System

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		lispdir=${PREFIX}/share/examples/prcs
INFO_FILES=		prcs.info
USE_LANGUAGES=		c c++
CONFIGURE_ENV+=		EMACS=no
CONFIGURE_ENV+=		SYS_GDIFF_COMMAND_PATH="${TOOLS_DIFF}"
CONFIGURE_ENV+=		SYS_TAR_COMMAND_PATH="${TOOLS_TAR}"
CONFIGURE_ENV+=		SYS_LS_COMMAND_PATH="${TOOLS_LS}"
USE_TOOLS+=		diff ls tar

GCC_REQD=		3.0

.include "../../mk/bsd.pkg.mk"
