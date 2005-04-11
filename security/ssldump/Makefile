# $NetBSD: Makefile,v 1.13 2005/04/11 21:47:20 tv Exp $
#

DISTNAME=	ssldump-0.9b3
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://www.rtfm.com/ssldump/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.rtfm.com/ssldump/
COMMENT=	SSLv3/TLS network protocol analyzer

GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make

CONFIGURE_ARGS+=--with-pcap-inc=${BUILDLINK_PREFIX.libpcap}/include \
		--with-pcap-lib=${BUILDLINK_PREFIX.libpcap}/lib \
		--with-openssl-inc=${BUILDLINK_PREFIX.openssl}/include \
		--with-openssl-lib=${BUILDLINK_PREFIX.openssl}/lib

.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
