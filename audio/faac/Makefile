# $NetBSD: Makefile,v 1.1.1.1 2004/05/16 01:51:21 xtraeme Exp $
#

DISTNAME=	faac-1.24
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=faac/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://faac.sourceforge.net/
COMMENT=	AAC audio encoder

USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/faac

LIBTOOLIZE=	${PREFIX}/bin/libtoolize

pre-configure:
	cd ${WRKSRC};						\
	${LIBTOOLIZE} --automake;				\
	${ACLOCAL};						\
	${AUTOHEADER};						\
	${AUTOMAKE} -a --foreign -i;				\
	${AUTOCONF}

.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
