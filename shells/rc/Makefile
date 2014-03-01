# $NetBSD: Makefile,v 1.29 2014/03/01 03:24:43 dholland Exp $

DISTNAME=       rc-1.7
PKGREVISION=	1
CATEGORIES=	shells plan9
MASTER_SITES=   http://www-ftp.lip6.fr/pub/unix/shells/rc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tobold.org/article/rc
#HOMEPAGE=	http://plan9.bell-labs.com/sys/doc/rc.html
COMMENT=	Unix incarnation of the plan9 shell

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-history

PKG_SHELL=	bin/rc

PKG_OPTIONS_VAR=	PKG_OPTIONS.rc
PKG_SUPPORTED_OPTIONS=	readline

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mreadline)
.include "../../devel/readline/buildlink3.mk"
CONFIGURE_ARGS+=        --with-readline
.endif

.include "../../mk/bsd.pkg.mk"
