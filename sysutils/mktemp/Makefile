# $NetBSD: Makefile,v 1.1.1.1 2002/12/13 09:32:08 salo Exp $
#

DISTNAME=	mktemp-1.4
CATEGORIES=	sysutils security
MASTER_SITES=	ftp://ftp.mktemp.org/pub/mktemp/ \
		ftp://ftp.cs.colorado.edu/pub/mktemp/ \
		ftp://ftp.usa.openbsd.org/pub/mktemp/ \
		ftp://ftp.wiretapped.net/pub/security/host-security/mktemp/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mktemp.org/
COMMENT=	Small program for safe temporary file and directory creation

NOT_FOR_PLATFORM=	NetBSD-1.[5-9]*-* FreeBSD-*-* OpenBSD-*-* # in base system

GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
