# $NetBSD: Makefile,v 1.7 1998/04/20 11:56:25 frueauf Exp $
# FreeBSD Id: Makefile,v 1.10 1997/08/27 19:31:37 jmacd Exp
#

DISTNAME=	scheme48-0.46
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp-swiss.ai.mit.edu/pub/s48/
EXTRACT_SUFX=	.tgz

MAINTAINER= 	packages@netbsd.org

GNU_CONFIGURE=  yes
CONFIGURE_ARGS+= --prefix=${PREFIX}
ALL_TARGET = 	enough
MAN1=		scheme48.1

.include "../../mk/bsd.pkg.mk"
