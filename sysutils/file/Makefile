# $NetBSD: Makefile,v 1.3 2003/07/17 22:53:34 grant Exp $

DISTNAME=		file-4.02
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.gw.com/mirrors/pub/unix/file/
MASTER_SITES+=		ftp://ftp.astron.com/pub/file/

MAINTAINER=		tech-pkg@NetBSD.org
#HOMEPAGE=
COMMENT=		tool for determining file type

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-fsect-man5
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

.include "../../mk/bsd.pkg.mk"
