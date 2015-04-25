# $NetBSD: Makefile,v 1.27 2015/04/25 14:20:21 tnn Exp $

DISTNAME=		kmp-0.01
PKGREVISION=		16
CATEGORIES=		audio
MASTER_SITES=		# http://mercury.chem.pitt.edu/~shank/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkg@burningsoda.com
#HOMEPAGE=		http://www.threadbox.net/index.php/code/kmp/
COMMENT=		Qt client for the Music Player Daemon

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	${PREFIX}

INSTALLATION_DIRS=	bin

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
# XXX Please verify whether qt3-tools is really needed at run-time.
# If it is, then remove this comment.  If it is not, then remove
# this comment and the line below, and bump PKGREVISION.
BUILDLINK_DEPMETHOD.qt3-tools=	full
.include "../../mk/bsd.pkg.mk"
