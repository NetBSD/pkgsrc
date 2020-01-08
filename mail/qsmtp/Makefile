# $NetBSD: Makefile,v 1.2 2020/01/08 01:20:36 schmonz Exp $

DISTNAME=		Qsmtp-0.37
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://opensource.sf-tec.de/Qsmtp/
COMMENT=		Drop-in replacement for qmail-smtpd and qmail-remote
LICENSE=		gnu-gpl-v2

BUILD_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen

USE_CMAKE=		yes
CMAKE_ARGS+=		-DAUTOQMAIL=${QMAILDIR}
CMAKE_ARGS+=		-DDOC_DESTINATION_DIRECTORY="share/doc/qsmtp/"
CMAKE_ARGS.Darwin+=	-DALLOW_INSECURE_BZERO=ON

BUILD_DEFS+=		QMAILDIR

.include "../../devel/libowfat/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
