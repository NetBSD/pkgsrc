# $NetBSD: Makefile,v 1.10 1999/07/13 01:20:13 jlam Exp $
#

DISTNAME=		coda-4.6.6
PKGNAME=		coda-server-4.6.6.1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.coda.cs.cmu.edu/pub/coda/src/
EXTRACT_SUFX=		.tgz

MAINTAINER=		rvb@cs.cmu.edu
HOMEPAGE=		http://www.coda.cs.cmu.edu/

DEPENDS+=		gdbm-1.7.3:../../databases/gdbm
DEPENDS+=		readline-4.0:../../devel/readline

ONLY_FOR_PLATFORM=	NetBSD-*-*
NOT_FOR_PLATFORM=	*-*-alpha	# needs custom asm.

ALL_TARGET=		coda
INSTALL_TARGET=		server-install

USE_PERL5=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

.include "../../mk/bsd.pkg.mk"
