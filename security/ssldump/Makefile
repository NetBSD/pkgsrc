# $NetBSD: Makefile,v 1.1.1.1 2000/10/31 01:17:40 hubertf Exp $
#

DISTNAME=	ssldump-0.9a2
CATEGORIES=	security
MASTER_SITES=	http://www.rtfm.com/ssldump/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.rtfm.com/ssldump/

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-pcap=/ \
		--with-pcap-inc=/usr/include \
		--with-pcap-lib=/usr/lib \
		--with-openssl=/ \
		--with-openssl-inc=/usr/include \
		--with-openssl-lib=/usr/lib

.include "../../mk/bsd.pkg.mk"
