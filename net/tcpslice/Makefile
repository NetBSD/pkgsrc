# $NetBSD: Makefile,v 1.2 2002/08/25 21:50:17 jlam Exp $

DISTNAME=	tcpslice-1.2a1
PKGNAME=	tcpslice-1.2.0.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ee.lbl.gov/

MAINTAINER=	seb@pbox.org
COMMENT=	tool for extracting portions of tcpdump's packet trace files

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
INSTALL_TARGET=	install install-man

.include "../../net/libpcap/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
