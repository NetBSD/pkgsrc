# $NetBSD: Makefile,v 1.3 1998/10/02 14:38:58 rvb Exp $
#

DISTNAME=	coda-4.6.5
PKGNAME=	coda-client-4.6.5.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/coda/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rvb@cs.cmu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/

DEPENDS+=	gdbm-*:../../databases/gdbm
DEPENDS+=	readline-*:../../devel/readline

ALL_TARGET=	coda
INSTALL_TARGET=	client-install

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include "../../mk/bsd.pkg.mk"
