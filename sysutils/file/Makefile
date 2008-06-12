# $NetBSD: Makefile,v 1.16 2008/06/12 02:14:46 joerg Exp $

DISTNAME=		file-4.21
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.gw.com/mirrors/pub/unix/file/
MASTER_SITES+=		ftp://ftp.astron.com/pub/file/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=
COMMENT=		Tool for determining file type

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-fsect-man5
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
