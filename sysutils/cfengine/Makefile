# $NetBSD: Makefile,v 1.17 2005/03/31 01:39:51 seb Exp $
#

DISTNAME=	cfengine-1.6.5
PKGREVISION=	1
CATEGORIES=	sysutils net
MASTER_SITES=	ftp://ftp.iu.hio.no/pub/cfengine/ \
		http://sunsite.utk.edu/ftp/pub/cfengine/cfengine-ftp/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cfengine.org/
COMMENT=	Automate configuration and administration of large systems

USE_BUILDLINK3=		YES
USE_OLD_DES_API=	YES
USE_GNU_TOOLS+=		lex
GNU_CONFIGURE=		YES
CONFIGURE_ARGS=		--without-pthreads

.include "../../security/openssl/buildlink3.mk"

pre-configure:
	cd ${WRKSRC};					\
	${ACLOCAL};					\
	${AUTOHEADER};					\
	${AUTOMAKE} -a --foreign -i;			\
	${AUTOCONF}

.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
