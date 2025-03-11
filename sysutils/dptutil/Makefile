# $NetBSD: Makefile,v 1.16 2025/03/11 12:29:25 nia Exp $

DISTNAME=		raidmgt-3.31
PKGNAME=		dptutil-3.31
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://www.NetBSD.org/~ad/raidmgt/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://opensource.adaptec.com/
COMMENT=		DPT/Adaptec Storage Management software (dptutil)

# Should work for 32-bit PowerPC and SPARC, but untested.  64-bit platforms
# may have problems.
ONLY_FOR_PLATFORM=	NetBSD-*-i386

USE_LANGUAGES=		c++
USE_TOOLS+=		makedepend
INSTALLATION_DIRS=	sbin

FORCE_CXX_STD=		gnu++98

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dpteng/dpteng \
		${DESTDIR}${PREFIX}/sbin/dpteng
	${INSTALL_PROGRAM} ${WRKSRC}/dptutil/raidutil \
		${DESTDIR}${PREFIX}/sbin/dptutil

.include "../../mk/bsd.pkg.mk"
