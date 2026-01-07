# $NetBSD: Makefile,v 1.108 2026/01/07 08:48:18 wiz Exp $

DISTNAME=		jigdo-0.8.2
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		https://www.einval.com/~steve/software/jigdo/download/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.einval.com/~steve/software/jigdo/
COMMENT=		Tool to ease downloading of large files from the Internet
LICENSE=		gnu-gpl-v2

MAKE_JOBS_SAFE=		no

USE_TOOLS+=			pkg-config wget:run
USE_LANGUAGES=			c c++
GNU_CONFIGURE=			yes
CONFIGURE_ARGS+=		--without-libdb
BROKEN_GETTEXT_DETECTION=	yes

pre-build:
	${CP} ${FILESDIR}/interface.hh ${WRKSRC}/src/gtk

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/docbook-utils/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
