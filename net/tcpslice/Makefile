# $NetBSD: Makefile,v 1.1.1.1.2.1 2002/07/01 17:45:04 jlam Exp $

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
