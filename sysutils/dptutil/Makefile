# $NetBSD: Makefile,v 1.5 2005/06/17 03:50:33 jlam Exp $

DISTNAME=		raidmgt-3.31
PKGNAME=		dptutil-3.31
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://www.interlude.eu.org/~ad/raidmgt/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://opensource.adaptec.com/
COMMENT=		DPT/Adaptec Storage Management software (dptutil)

# Should work for 32-bit PowerPC and SPARC, but untested.  64-bit platforms
# may have problems.
ONLY_FOR_PLATFORM=	NetBSD-*-i386

INSTALLATION_DIRS=	bni

post-patch:
	${SED}	-e "s,@SBINDIR@,${PREFIX}/sbin,g"			\
		${WRKSRC}/dpteng/makefile > ${WRKSRC}/dpteng/makefile.tmp
	${MV} ${WRKSRC}/dpteng/makefile.tmp ${WRKSRC}/dpteng/makefile
	${SED}	-e "s,@SBINDIR@,${PREFIX}/sbin,g"			\
		${WRKSRC}/dptutil/makefile > ${WRKSRC}/dptutil/makefile.tmp
	${MV} ${WRKSRC}/dptutil/makefile.tmp ${WRKSRC}/dptutil/makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dpteng/dpteng ${PREFIX}/sbin/dpteng
	${INSTALL_PROGRAM} ${WRKSRC}/dptutil/raidutil ${PREFIX}/sbin/dptutil

.include "../../mk/bsd.pkg.mk"
