# $NetBSD: Makefile,v 1.2 2003/06/02 01:21:30 jschauma Exp $
#

DISTNAME=	liveice-xmms
PKGNAME=	xmms-liveice-1.0.0
WRKSRC=         ${WRKDIR}/LiveIce-1.0.0
CATEGORIES=	audio
MASTER_SITES=	http://star.arm.ac.uk/~spm/software/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://star.arm.ac.uk/~spm/software/
COMMENT=	Audio streaming plugin for XMMS

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CFLAGS+=		-DLAME=\"\\\"${BUILDLINK_PREFIX.lame}/bin/lame\\\"\"

.include "../../audio/lame/buildlink2.mk"
.include "../../audio/xmms/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
