# $NetBSD: Makefile,v 1.8 2023/09/25 12:52:52 schmonz Exp $

DISTNAME=		Qsmtp-0.39
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://opensource.sf-tec.de/Qsmtp/
COMMENT=		Drop-in replacement for qmail-smtpd and qmail-remote
LICENSE=		gnu-gpl-v2

USE_CMAKE=		yes
CMAKE_ARGS+=		-DAUTOQMAIL=${QMAILDIR}

CFLAGS.SunOS+=		-D__EXTENSIONS__

BUILD_DEFS+=		QMAILDIR

TEST_TARGET=		test

.include "../../devel/libowfat/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
