# $NetBSD: Makefile,v 1.6 2003/10/04 10:23:16 jlam Exp $
#

DISTNAME=	pdksh-5.2.14
PKGREVISION=	1
CATEGORIES=	shells
MASTER_SITES=	ftp://ftp.cs.mun.ca/pub/pdksh/ \
		http://gd.tuwien.ac.at/utils/shells/pdksh/ \
		ftp://ftp.lip6.fr/pub/unix/shells/pdksh/ \
		ftp://ftp.demon.net/pub/mirrors/pdksh/ \
		ftp://ftp.rge.com/pub/shells/pdksh/ \
		ftp://pink.seudns.net/pub/mirrors/pdksh/

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://web.cs.mun.ca/~michael/pdksh/
COMMENT=	Free clone of the AT&T Korn shell

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=pd

USE_PKGINSTALL=	yes
PKG_SHELL=	${PREFIX}/bin/pdksh

.include "../../mk/bsd.pkg.mk"
