# $NetBSD: Makefile,v 1.33 2005/03/24 21:12:53 wiz Exp $

DISTNAME= 		prcs-1.3.3
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

GCC_REQD=		3.0

.include "../../mk/bsd.pkg.mk"
