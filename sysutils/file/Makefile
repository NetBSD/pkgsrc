# $NetBSD: Makefile,v 1.5 2004/02/05 02:10:39 reed Exp $

DISTNAME=		file-4.02
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.gw.com/mirrors/pub/unix/file/
MASTER_SITES+=		ftp://ftp.astron.com/pub/file/

MAINTAINER=		tech-pkg@NetBSD.org
#HOMEPAGE=
COMMENT=		Tool for determining file type

USE_BUILDLINK3= 	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-fsect-man5
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
