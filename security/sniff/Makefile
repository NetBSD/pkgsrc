# $NetBSD: Makefile,v 1.1.1.1 2001/03/13 13:13:41 zuntum Exp $
#

DISTNAME=	sniff-1.0
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/ports/distfiles/	\
		ftp://ftp.pl.freebsd.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	zuntum@netbsd.org
COMMENT=	Program to sniff logins and passwords

HAS_CONFIGURE=	YES

MAKE_ENV+=	"CC=${CC}"						\
		"PREFIX=${PREFIX}"

.include "../../mk/bsd.pkg.mk"
