# $NetBSD: Makefile,v 1.32 2004/12/12 16:10:37 kristerw Exp $
# FreeBSD Id: Makefile,v 1.9 1997/10/13 05:11:40 jmacd Exp
#

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
