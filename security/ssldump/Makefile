# $NetBSD: Makefile,v 1.5 2003/07/17 22:53:17 grant Exp $
#

DISTNAME=	ssldump-0.9b3
CATEGORIES=	security
MASTER_SITES=	http://www.rtfm.com/ssldump/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.rtfm.com/ssldump/
COMMENT=	SLv3/TLS network protocol analyzer

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES

CONFIGURE_ARGS+=--with-pcap-inc=${BUILDLINK_PREFIX.libpcap}/include \
		--with-pcap-lib=${BUILDLINK_PREFIX.libpcap}/lib \
		--with-openssl-inc=${BUILDLINK_PREFIX.openssl}/include \
		--with-openssl-lib=${BUILDLINK_PREFIX.openssl}/lib

.include "../../net/libpcap/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
