# $NetBSD: Makefile,v 1.11 2006/03/04 21:30:41 jlam Exp $

DISTNAME=		file-4.13
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.gw.com/mirrors/pub/unix/file/
MASTER_SITES+=		ftp://ftp.astron.com/pub/file/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=
COMMENT=		Tool for determining file type

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-fsect-man5
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
