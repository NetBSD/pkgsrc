# $NetBSD: Makefile,v 1.7 1999/04/09 21:11:14 hubertf Exp $
#

DISTNAME=	coda-4.6.6
PKGNAME=	coda-client-4.6.6.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/coda/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rvb@cs.cmu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/

DEPENDS+=	gdbm-1.7.3:../../databases/gdbm
DEPENDS+=	readline-2.2:../../devel/readline

ALL_TARGET=	coda
INSTALL_TARGET=	client-install

USE_PERL5=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include "../../mk/bsd.pkg.mk"
