# $NetBSD: Makefile,v 1.12 2025/07/01 00:54:08 schmonz Exp $

DISTNAME=		Qsmtp-0.39
PKGREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://opensource.sf-tec.de/Qsmtp/
COMMENT=		Drop-in replacement for qmail-smtpd and qmail-remote
LICENSE=		gnu-gpl-v2

CMAKE_CONFIGURE_ARGS+=	-DAUTOQMAIL=${QMAILDIR}

CFLAGS.SunOS+=		-D__EXTENSIONS__

BUILD_DEFS+=		QMAILDIR

TEST_TARGET=		test

.include "../../devel/cmake/build.mk"
.include "../../devel/libowfat/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
