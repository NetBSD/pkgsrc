# $NetBSD: Makefile,v 1.13 2007/02/22 19:26:08 wiz Exp $
#

DISTNAME=	liveice-xmms
PKGNAME=	xmms-liveice-1.0.0
PKGREVISION=	         3
CATEGORIES=	audio
MASTER_SITES=	http://star.arm.ac.uk/~spm/software/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://star.arm.ac.uk/~spm/software/
COMMENT=	Audio streaming plugin for XMMS

WRKSRC=		${WRKDIR}/LiveIce-1.0.0
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

CFLAGS+=		-DLAME="\"${BUILDLINK_PREFIX.lame}/bin/lame\""

.include "../../audio/lame/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
