# $NetBSD: Makefile,v 1.28 2003/12/30 17:21:55 cjep Exp $
# FreeBSD Id: Makefile,v 1.9 1997/10/13 05:11:40 jmacd Exp
#

DISTNAME= 		prcs-1.2.15
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.xcf.berkeley.edu/pub/prcs/

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

.include "../../mk/bsd.pkg.mk"
