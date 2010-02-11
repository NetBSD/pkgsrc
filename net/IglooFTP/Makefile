# $NetBSD: Makefile,v 1.16 2010/02/11 20:22:22 joerg Exp $

DISTNAME=	IglooFTP-0.6.1
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SUNSITE:=system/network/file-transfer/}
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://www.littleigloo.org/iglooftp.php3
COMMENT=	Easy to use FTP client for X Window System

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DIRS=	src

post-extract:
	${RM} ${WRKSRC}/share/docs/LICENSE~

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "DragonFly"
LDFLAGS.resolv=
.else
LDFLAGS.resolv=	-lresolv
.endif

MAKE_ENV+=	LDFLAGS.resolv=${LDFLAGS.resolv:Q}

INSTALLATION_DIRS+=	bin

.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
