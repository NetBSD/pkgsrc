# $NetBSD: Makefile,v 1.2 2020/01/18 23:30:13 rillig Exp $

DISTNAME=		srtp-1.4.4
CATEGORIES=		comms security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=srtp/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://srtp.sourceforge.net/
COMMENT=		Secure Real-time Transport Protocol library

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

LDFLAGS.SunOS+=		-lsocket -lnsl
TEST_TARGET=		runtest

WRKSRC=			${WRKDIR}/srtp

.include "../../mk/bsd.pkg.mk"
