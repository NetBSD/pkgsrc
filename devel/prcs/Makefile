# $NetBSD: Makefile,v 1.16 2001/05/17 08:38:44 abs Exp $
# FreeBSD Id: Makefile,v 1.9 1997/10/13 05:11:40 jmacd Exp
#

DISTNAME= 		prcs-1.2.9
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.xcf.berkeley.edu/pub/prcs/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.XCF.Berkeley.EDU/~jmacd/prcs.html
COMMENT=		Project Revision Control System

ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-arm32 NetBSD-*-i386 \
			NetBSD-*-mips* NetBSD-*-pc532 NetBSD-*-powerpc \
			NetBSD-*-sparc NetBSD-*-vax SunOS-*-*

GNU_CONFIGURE=		yes
USE_GTEXINFO=		yes

post-install:
			${INSTALL_DATA_DIR} ${PREFIX}/share/examples/prcs
			${INSTALL_DATA} ${WRKSRC}/emacs/*.el* ${PREFIX}/share/examples/prcs

.include "../../mk/bsd.pkg.mk"
