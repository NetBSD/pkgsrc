# $NetBSD: Makefile,v 1.6 2004/02/14 17:21:34 jlam Exp $
#

DISTNAME=	liveice-xmms
PKGNAME=	xmms-liveice-1.0.0
PKGREVISION=	         1
CATEGORIES=	audio
MASTER_SITES=	http://star.arm.ac.uk/~spm/software/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://star.arm.ac.uk/~spm/software/
COMMENT=	Audio streaming plugin for XMMS

WRKSRC=         	${WRKDIR}/LiveIce-1.0.0
GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes

CFLAGS+=		-DLAME=\"\\\"${BUILDLINK_PREFIX.lame}/bin/lame\\\"\"

.include "../../audio/lame/buildlink2.mk"
.include "../../audio/xmms/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
