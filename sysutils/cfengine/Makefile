# $NetBSD: Makefile,v 1.13 2003/07/17 22:53:29 grant Exp $
#

DISTNAME=	cfengine-1.6.5
CATEGORIES=	sysutils net
MASTER_SITES=	ftp://ftp.iu.hio.no/pub/cfengine/ \
		http://sunsite.utk.edu/ftp/pub/cfengine/cfengine-ftp/

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://www.cfengine.org/
COMMENT=	Automate configuration and administration of large systems

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS=		--without-pthreads

pre-configure:
	cd ${WRKSRC};					\
	${ACLOCAL};					\
	${AUTOHEADER};					\
	${AUTOMAKE} -a --foreign -i;			\
	${AUTOCONF}

.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
