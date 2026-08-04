# $NetBSD: Makefile,v 1.22 2026/08/04 20:29:10 wiz Exp $

DISTNAME=	IglooFTP-0.6.1
PKGREVISION=	7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SUNSITE:=system/network/file-transfer/}
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	rxg@NetBSD.org
#HOMEPAGE=	http://www.littleigloo.org/iglooftp.php3
COMMENT=	Easy to use FTP client for X Window System

BUILD_DIRS=	src

post-extract:
	${RM} ${WRKSRC}/share/docs/LICENSE~

OPSYSVARS+=			LDFLAGS.resolv
LDFLAGS.resolv.DragonFly=	# empty
LDFLAGS.resolv.*=		-lresolv

MAKE_ENV+=	LDFLAGS.resolv=${LDFLAGS.resolv:Q}

INSTALLATION_DIRS+=	bin

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
