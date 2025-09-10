# $NetBSD: Makefile,v 1.8 2025/09/10 10:34:02 vins Exp $

DISTNAME=	libasr-20240904
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/vins/dists/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://man.openbsd.org/asr_run.3
COMMENT=	Asynchronous DNS resolver library
LICENSE=	isc AND modified-bsd AND 2-clause-bsd

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

CFLAGS.NetBSD+=		-D_OPENBSD_SOURCE	# strtonum()
LDFLAGS.SunOS+=		-lresolv -lsocket -lnsl	# libresolv(3LIB)

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
