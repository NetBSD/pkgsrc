# New makefile for:	coda server
# Version required:	4.6.5
# Date created:		19 June 1998
# Whom:			hmpierce <hmpierce@cs.cmu.edu>
#
# $Id: Makefile,v 1.1.1.1 1998/09/29 17:20:47 rvb Exp $
#

DISTNAME=	coda-4.6.5
PKGNAME=	coda-server-4.6.5-1.3H-1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/coda/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	coda@cs.cmu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/

# Dependencies:
DEPENDS=	gdbm-*:../../databases/gdbm \
		readline-*:../../devel/readline

ALL_TARGET=	coda
INSTALL_TARGET=	server-install

# Odd, non-default BSD stuff:
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include "../../mk/bsd.pkg.mk"
