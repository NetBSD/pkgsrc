# $NetBSD: Makefile,v 1.2 2002/11/28 07:42:05 jlam Exp $
#

DISTNAME=	pdksh-5.2.14
PKGREVISION=	1
CATEGORIES=	shells
MASTER_SITES=	ftp://ftp.cs.mun.ca/pub/pdksh/

MAINTAINER=	schmonz@netbsd.org
HOMEPAGE=	http://web.cs.mun.ca/~michael/pdksh/
COMMENT=	Free clone of the AT&T Korn shell

# pdksh is needed to bootstrap buildlink2 on some systems.
USE_BUILDLINK2=	no

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=pd

PKG_SHELL=	${PREFIX}/bin/pdksh

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"

LDFLAGS=	# empty
