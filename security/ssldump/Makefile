# $NetBSD: Makefile,v 1.19 2008/01/18 05:09:42 tnn Exp $
#

DISTNAME=	ssldump-0.9b3
PKGREVISION=	7
CATEGORIES=	security
MASTER_SITES=	http://www.rtfm.com/ssldump/

MAINTAINER=	pkgsrc-users@NetBSD.org
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
