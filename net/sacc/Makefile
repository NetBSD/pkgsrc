# $NetBSD: Makefile,v 1.6 2021/01/06 14:26:03 leot Exp $

DISTNAME=	sacc-1.03
CATEGORIES=	net
MASTER_SITES=	ftp://bitreich.org/releases/sacc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	gopher://bitreich.org/1/scm/sacc
COMMENT=	Console gopher client
LICENSE=	isc

MAKE_FLAGS+=	PREFIX="${PREFIX}"
MAKE_FLAGS+=	MANDIR="${PREFIX}/${PKGMANDIR}/man1"
MAKE_FLAGS+=	LIBS=${BUILDLINK_LDADD.terminfo:Q}

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE	# strcasestr, asprintf
LDFLAGS.SunOS+=	-lsocket -lnsl

USE_LANGUAGES=	c99

.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
