# $NetBSD: Makefile,v 1.8 1999/02/22 00:31:36 hubertf Exp $
#

DISTNAME=	coda-5.0.1
PKGNAME=	coda-client-5.0.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/coda/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rvb@cs.cmu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/

DEPENDS+=	gdbm-1.7.3:../../databases/gdbm
DEPENDS+=	readline-2.2:../../devel/readline
DEPENDS+=	perl-5.00404:../../lang/perl5

ONLY_FOR_ARCHS=	arm32 i386 ns32k

ALL_TARGET=	coda
INSTALL_TARGET=	client-install

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include "../../mk/bsd.pkg.mk"
