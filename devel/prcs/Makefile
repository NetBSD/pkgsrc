# $NetBSD: Makefile,v 1.36 2005/12/05 20:50:07 rillig Exp $

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
CONFIGURE_ENV+=		SYS_GDIFF_COMMAND_PATH=${TOOLS_DIFF:Q}
CONFIGURE_ENV+=		SYS_TAR_COMMAND_PATH=${TOOLS_TAR:Q}
CONFIGURE_ENV+=		SYS_LS_COMMAND_PATH=${TOOLS_LS:Q}
USE_TOOLS+=		diff ls tar

GCC_REQD+=		3.0

.include "../../mk/bsd.pkg.mk"
