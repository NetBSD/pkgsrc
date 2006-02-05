# $NetBSD: Makefile,v 1.16 2006/02/05 23:10:47 joerg Exp $
#

DISTNAME=	ssldump-0.9b3
PKGREVISION=	5
CATEGORIES=	security
MASTER_SITES=	http://www.rtfm.com/ssldump/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.rtfm.com/ssldump/
COMMENT=	SSLv3/TLS network protocol analyzer

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=--with-pcap-inc=${BUILDLINK_PREFIX.libpcap}/include \
		--with-pcap-lib=${BUILDLINK_PREFIX.libpcap}/lib \
		--with-openssl-inc=${BUILDLINK_PREFIX.openssl}/include \
		--with-openssl-lib=${BUILDLINK_PREFIX.openssl}/lib

.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
