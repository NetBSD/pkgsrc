# $NetBSD: Makefile,v 1.27 2001/05/15 08:32:48 phil Exp $
#

DISTNAME=		coda-5.3.13
PKGNAME=		coda-server-5.3.13
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.coda.cs.cmu.edu/pub/coda/src/

MAINTAINER=		phil@cs.wwu.edu
HOMEPAGE=		http://www.coda.cs.cmu.edu/
COMMENT=		server programs for a replicated high-performance network file system

DEPENDS+=		lwp>=1.6:../../devel/lwp
DEPENDS+=		rvm>=1.3:../../devel/rvm
DEPENDS+=		rpc2>=1.10:../../devel/rpc2
DEPENDS+=		readline>=4.0:../../devel/readline

# Only enable platforms that can build "lwp".
ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-m68k NetBSD-*-sparc

ALL_TARGET=		coda
INSTALL_TARGET=		server-install

USE_PERL5=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

CONFIGURE_ENV+=		CFLAGS="${CFLAGS} -I${WRKSRC}/include"
CONFIGURE_ENV+=		CXXFLAGS="${CXXFLAGS} -I${WRKSRC}/include"

.include "../../mk/bsd.pkg.mk"
