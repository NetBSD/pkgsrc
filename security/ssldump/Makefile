# $NetBSD: Makefile,v 1.3 2001/02/17 17:50:11 wiz Exp $
#

DISTNAME=	ssldump-0.9a2
CATEGORIES=	security
MASTER_SITES=	http://www.rtfm.com/ssldump/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.rtfm.com/ssldump/
COMMENT=	SLv3/TLS network protocol analyzer

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-pcap-inc=/usr/include \
		--with-pcap-lib=/usr/lib \
		--with-openssl-inc=/usr/include \
		--with-openssl-lib=/usr/lib

.include "../../mk/bsd.pkg.mk"
