# $NetBSD: Makefile,v 1.25 2010/02/04 05:23:27 dholland Exp $

DISTNAME=       rc-1.7
CATEGORIES=	shells plan9
MASTER_SITES=   http://www-ftp.lip6.fr/pub/unix/shells/rc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://plan9.bell-labs.com/sys/doc/rc.html
COMMENT=	Unix incarnation of the plan9 shell

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-history

PKG_SHELL=	bin/rc

PKG_OPTIONS_VAR=	PKG_OPTIONS.rc
PKG_SUPPORTED_OPTIONS=	readline

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mreadline)
.include "../../devel/readline/buildlink3.mk"
CONFIGURE_ARGS+=        --with-readline
USE_GNU_READLINE=	YES
.endif

.include "../../mk/bsd.pkg.mk"
