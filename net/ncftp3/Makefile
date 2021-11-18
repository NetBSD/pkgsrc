# $NetBSD: Makefile,v 1.35 2021/11/18 14:07:20 nia Exp $

DISTNAME=	ncftp-3.2.6-src
PKGNAME=	${DISTNAME:S/ncftp/ncftp3/:S/-src//}
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ncftp.com/ncftp/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ncftp.com/
COMMENT=	FTP replacement with advanced user interface
LICENSE=	artistic

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}

USE_TOOLS+=		perl:build
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-universal

.include "../../mk/bsd.prefs.mk"
.if !empty(PKGSRC_COMPILER:M*gcc*)
CONFIGURE_ARGS+=	--disable-precomp
.endif

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
