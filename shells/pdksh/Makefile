# $NetBSD: Makefile,v 1.13 2007/11/12 20:05:38 heinz Exp $
#

DISTNAME=	pdksh-5.2.14
PKGREVISION=	2
CATEGORIES=	shells
MASTER_SITES=	ftp://ftp.cs.mun.ca/pub/pdksh/ \
		http://gd.tuwien.ac.at/utils/shells/pdksh/ \
		ftp://ftp.lip6.fr/pub/unix/shells/pdksh/ \
		ftp://ftp.demon.net/pub/mirrors/pdksh/ \
		ftp://pink.seudns.net/pub/mirrors/pdksh/

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://web.cs.mun.ca/~michael/pdksh/
COMMENT=	Free clone of the AT&T Korn shell

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--program-prefix=pd

PKG_SHELL=	bin/pdksh

.include "../../mk/bsd.pkg.mk"
