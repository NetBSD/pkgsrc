# $NetBSD: Makefile,v 1.30 2004/06/25 16:43:54 wiz Exp $
# FreeBSD Id: Makefile,v 1.9 1997/10/13 05:11:40 jmacd Exp
#

DISTNAME= 		prcs-1.3.3
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=prcs/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://prcs.sourceforge.net/
COMMENT=		Project Revision Control System

ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-arm NetBSD-*-arm32	\
			NetBSD-*-i386 NetBSD-*-mips* NetBSD-*-pc532	\
			NetBSD-*-powerpc NetBSD-*-sparc NetBSD-*-vax 	\
			SunOS-*-*

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		lispdir=${PREFIX}/share/examples/prcs
INFO_FILES=		prcs.info
USE_LANGUAGES=		c c++
CONFIGURE_ENV+=		EMACS=no

.include "../../mk/bsd.pkg.mk"
