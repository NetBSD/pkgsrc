# $NetBSD: Makefile,v 1.12 2014/08/14 19:44:53 shattered Exp $

DISTNAME=	tcpslice-1.2a3
PKGNAME=	tcpslice-1.2.0.3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ee.lbl.gov/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tool for extracting portions of tcpdump's packet trace files

GNU_CONFIGURE=	YES
INSTALL_TARGET=	install install-man

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
