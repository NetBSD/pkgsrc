# $NetBSD: Makefile,v 1.10 1999/04/09 21:11:14 hubertf Exp $
#

DISTNAME=	coda-5.2.0
PKGNAME=	coda-server-5.2.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/coda/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rvb@cs.cmu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/

DEPENDS+=	gdbm-1.7.3:../../databases/gdbm
DEPENDS+=	readline-2.2:../../devel/readline

ONLY_FOR_ARCHS=	arm32 i386 ns32k

#LICENSE=	GPL

ALL_TARGET=	coda
INSTALL_TARGET=	server-install

USE_PERL5=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include "../../mk/bsd.pkg.mk"
