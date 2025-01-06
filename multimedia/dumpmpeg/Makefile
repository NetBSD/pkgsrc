# $NetBSD: Makefile,v 1.17 2025/01/06 21:49:23 ktnb Exp $
#

DISTNAME=	dumpmpeg-0.6
PKGREVISION=	10
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dumpmpeg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/dumpmpeg
COMMENT=	Splits an MPEG stream into single images

GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--disable-smpegtest

.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
