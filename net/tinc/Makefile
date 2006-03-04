# $NetBSD: Makefile,v 1.6 2006/03/04 21:30:25 jlam Exp $
#

DISTNAME=	tinc-1.0.4
CATEGORIES=	net
MASTER_SITES=	http://tinc.nl.linux.org/packages/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tinc.nl.linux.org/
COMMENT=	Virtual Private Network (VPN) daemon

GNU_CONFIGURE=	yes

INFO_FILES=	tinc.info

.include "../../archivers/liblzo/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
