# $NetBSD: Makefile,v 1.1.1.1 2004/10/10 03:13:07 reed Exp $

DISTNAME=		strace-4.5.7
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=strace/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.liacs.nl/~wichert/strace/
COMMENT=		System call tracing utility

GNU_CONFIGURE=		YES

# operating system netbsdelf is not supported by strace
# XXX  for Linux, SunOS 4.x, System V release 4, Solaris 2.x and Irix 5.x
# XXX  only tested under Linux
ONLY_FOR_PLATFORM=     Linux-*-*

.include "../../mk/bsd.pkg.mk"
