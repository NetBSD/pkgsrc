# $NetBSD: Makefile,v 1.11 2013/02/06 19:31:01 jperkin Exp $

DISTNAME=	tcpslice-1.2a1
PKGNAME=	tcpslice-1.2.0.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ee.lbl.gov/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tool for extracting portions of tcpdump's packet trace files

GNU_CONFIGURE=	YES
INSTALL_TARGET=	install install-man

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
