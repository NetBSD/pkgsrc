# $NetBSD: Makefile,v 1.20.2.1 2002/06/23 18:44:53 jlam Exp $
# FreeBSD Id: Makefile,v 1.9 1997/10/13 05:11:40 jmacd Exp
#

DISTNAME= 		prcs-1.2.15
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.xcf.berkeley.edu/pub/prcs/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://prcs.sourceforge.net
COMMENT=		Project Revision Control System

ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-arm32 NetBSD-*-i386 	\
			NetBSD-*-mips* NetBSD-*-pc532 NetBSD-*-powerpc	\
			NetBSD-*-sparc NetBSD-*-vax NetBSD-*-arm 	\
			SunOS-*-* 

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		lispdir=${PREFIX}/share/examples/prcs

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
