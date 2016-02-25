# $NetBSD: Makefile,v 1.19 2016/02/25 16:20:50 jperkin Exp $

DISTNAME=	IglooFTP-0.6.1
PKGREVISION=	6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SUNSITE:=system/network/file-transfer/}
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://www.littleigloo.org/iglooftp.php3
COMMENT=	Easy to use FTP client for X Window System

BUILD_DIRS=	src

post-extract:
	${RM} ${WRKSRC}/share/docs/LICENSE~

OPSYSVARS+=			LDFLAGS.resolv
LDFLAGS.resolv.DragonFly=	# empty
LDFLAGS.resolv.*=		-lresolv

MAKE_ENV+=	LDFLAGS.resolv=${LDFLAGS.resolv:Q}

INSTALLATION_DIRS+=	bin

.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
