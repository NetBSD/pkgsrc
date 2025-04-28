# $NetBSD: Makefile,v 1.1 2025/04/28 13:25:29 wiz Exp $

DISTNAME=	epic5-3.0.3
CATEGORIES=	chat
MASTER_SITES=	https://ftp.epicsol.org/pub/epic/EPIC5-PRODUCTION/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ftp.epicsol.org/pub/epic/EPIC5-PRODUCTION/
COMMENT=	The (E)nhanced (P)rogrammable (I)RC-II (C)lient
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes

USE_TOOLS+=	perl

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
