# $NetBSD: Makefile,v 1.1.1.1 2003/04/13 10:24:27 cjep Exp $

DISTNAME=		file-4.02
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.gw.com/mirrors/pub/unix/file/
MASTER_SITES+=		ftp://ftp.astron.com/pub/file/

MAINTAINER=		packages@netbsd.org
#HOMEPAGE=
COMMENT=		tool for determining file type

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-fsect-man5
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

.include "../../mk/bsd.pkg.mk"
