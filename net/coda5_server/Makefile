# $NetBSD: Makefile,v 1.6 1998/10/09 20:45:15 rvb Exp $
#

DISTNAME=	coda-4.6.6
PKGNAME=	coda-server-4.6.6.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/coda/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rvb@cs.cmu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/

DEPENDS+=	gdbm-1.7.3:../../databases/gdbm
DEPENDS+=	readline-2.2:../../devel/readline
DEPENDS+=	perl-5.00404:../../lang/perl5

ALL_TARGET=	coda
INSTALL_TARGET=	server-install

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include "../../mk/bsd.pkg.mk"
