# $NetBSD: Makefile,v 1.15 1999/06/04 23:45:41 rvb Exp $
#

DISTNAME=		coda-5.2.4
PKGNAME=		coda-server-5.2.4
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.coda.cs.cmu.edu/pub/coda/src/
EXTRACT_SUFX=		.tgz

MAINTAINER=		rvb@cs.cmu.edu
HOMEPAGE=		http://www.coda.cs.cmu.edu/

DEPENDS=		gdbm-1.7.3:../../databases/gdbm \
			readline-2.2:../../devel/readline

ONLY_FOR_PLATFORM=	*-*-{arm32,i386,ns32k}

#LICENSE=		GPL

ALL_TARGET=		coda
INSTALL_TARGET=		server-install

USE_PERL5=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

.include "../../mk/bsd.pkg.mk"
