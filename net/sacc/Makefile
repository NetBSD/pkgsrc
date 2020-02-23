# $NetBSD: Makefile,v 1.4 2020/02/23 20:17:26 leot Exp $

DISTNAME=	sacc-1.01
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
