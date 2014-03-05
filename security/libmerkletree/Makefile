# $NetBSD: Makefile,v 1.1.1.1 2014/03/05 05:25:18 agc Exp $

DISTNAME=	libmerkletree-${VERSION}
CATEGORIES=	security
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/
COMMENT=	Calculate and verify Merkle tree digests
LICENSE=	modified-bsd

FILESDIR=	${.CURDIR}/../../security/merkletree/files

GNU_CONFIGURE=	yes
.if !defined(BOOTSTRAP)
USE_LIBTOOL=	yes
.endif
AUTO_MKDIRS=	yes

.include "../../mk/bsd.prefs.mk"

VERSION!=	${AWK} '/\#define.*MERKLETREE_H_/ {print $$3}' ${FILESDIR}/merkletree.h

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}
.if defined(BOOTSTRAP)
	cd ${WRKSRC} && ${CP} Makefile.lib.in Makefile.in
.else
	cd ${WRKSRC} && ${CP} Makefile.libtool.in Makefile.in
.endif

.include "../../security/libmultigest/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
