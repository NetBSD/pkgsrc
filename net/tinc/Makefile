# $NetBSD: Makefile,v 1.3 2004/10/03 00:18:00 tv Exp $
#

DISTNAME=	tinc-1.0.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://tinc.nl.linux.org/packages/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://tinc.nl.linux.org/
COMMENT=	Virtual Private Network (VPN) daemon

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes

INFO_FILES=	tinc.info

.include "../../archivers/liblzo/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
