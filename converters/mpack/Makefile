# $NetBSD: Makefile,v 1.10 2002/12/05 16:45:21 is Exp $
# FreeBSD Id: Makefile,v 1.7 1997/04/26 23:55:23 asami Exp
#

DISTNAME=	mpack-1.5-src
PKGNAME=	mpack-1.5
WRKSRC=		${WRKDIR}/mpack
CATEGORIES=	converters mail news
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/mpack/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org
COMMENT=	External MIME packer/unpacker

USE_BUILDLINK2=	# defined

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == SunOS
LDFLAGS+=	-lsocket -lnsl
.endif

.include "../../mk/bsd.pkg.mk"
