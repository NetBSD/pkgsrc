# $NetBSD: Makefile,v 1.9 1999/03/18 02:34:15 rvb Exp $
#

DISTNAME=	coda-5.2.0
PKGNAME=	coda-client-5.2.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/coda/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rvb@cs.cmu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/

DEPENDS+=	gdbm-1.7.3:../../databases/gdbm
DEPENDS+=	readline-2.2:../../devel/readline
DEPENDS+=	perl-5.00404:../../lang/perl5

ONLY_FOR_ARCHS=	arm32 i386 ns32k

#LICENSE=	GPL

ALL_TARGET=	coda
INSTALL_TARGET=	client-install

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include "../../mk/bsd.pkg.mk"
