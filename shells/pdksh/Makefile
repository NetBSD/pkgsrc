# $NetBSD: Makefile,v 1.1.1.1 2002/11/28 07:12:09 schmonz Exp $
#

DISTNAME=	pdksh-5.2.14
CATEGORIES=	shells
MASTER_SITES=	ftp://ftp.cs.mun.ca/pub/pdksh/

MAINTAINER=	schmonz@netbsd.org
HOMEPAGE=	http://web.cs.mun.ca/~michael/pdksh/
COMMENT=	Free clone of the AT&T Korn shell

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

PKG_SHELL=	${PREFIX}/bin/ksh

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
