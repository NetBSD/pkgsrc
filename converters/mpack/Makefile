# $NetBSD: Makefile,v 1.11 2003/06/02 01:21:16 jschauma Exp $
# FreeBSD Id: Makefile,v 1.7 1997/04/26 23:55:23 asami Exp
#

DISTNAME=	mpack-1.5-src
PKGNAME=	mpack-1.5
WRKSRC=		${WRKDIR}/mpack
CATEGORIES=	converters mail news
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/mpack/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	External MIME packer/unpacker

USE_BUILDLINK2=	# defined

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == SunOS
LDFLAGS+=	-lsocket -lnsl
.endif

.include "../../mk/bsd.pkg.mk"
