# $NetBSD: Makefile,v 1.28 2001/04/27 19:05:45 phil Exp $
#

DISTNAME=		coda-5.3.13
PKGNAME=		coda-client-5.3.13
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.coda.cs.cmu.edu/pub/coda/src/
#EXTRACT_SUFX=		.tar.gz

MAINTAINER=		phil@cs.wwu.edu
HOMEPAGE=		http://www.coda.cs.cmu.edu/
COMMENT=		client programs for a replicated high-performance network file system

DEPENDS+=		lwp>=1.6:../../devel/lwp
DEPENDS+=		rvm>=1.3:../../devel/rvm
DEPENDS+=		rpc2>=1.10:../../devel/rpc2
DEPENDS+=		readline>=4.0:../../devel/readline

# Requires "lwp" plus "filesystem CODA" to operate. Should build on
# any NetBSD-*-m68k, though.
ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-m68k NetBSD-*-sparc* NetBSD-*-arm32

ALL_TARGET=		coda
INSTALL_TARGET=		client-install

USE_PERL5=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

CONFIGURE_ENV+=		CFLAGS="${CFLAGS} -I${WRKSRC}/include"
CONFIGURE_ENV+=		CXXFLAGS="${CXXFLAGS} -I${WRKSRC}/include"

.include "../../mk/bsd.pkg.mk"
