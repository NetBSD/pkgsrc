# $NetBSD: Makefile,v 1.15 2001/02/17 18:18:44 wiz Exp $
#

DISTNAME=		coda-4.6.6
PKGNAME=		coda-server-4.6.6.1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.coda.cs.cmu.edu/pub/coda/src/
EXTRACT_SUFX=		.tgz

MAINTAINER=		rvb@cs.cmu.edu
HOMEPAGE=		http://www.coda.cs.cmu.edu/
COMMENT=		server for a replicated high-performance network file system

DEPENDS+=		gdbm>=1.7.3:../../databases/gdbm
DEPENDS+=		readline>=4.0:../../devel/readline

# Only enable platforms that can build "lwp".
ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-m68k

ALL_TARGET=		coda
INSTALL_TARGET=		server-install

USE_PERL5=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

.include "../../mk/bsd.pkg.mk"
