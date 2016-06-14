# $NetBSD: Makefile,v 1.1 2016/06/14 06:39:37 kamil Exp $
#

DISTNAME=	i3status-2.10
CATEGORIES=	sysutils
MASTER_SITES=	http://i3wm.org/i3status/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://i3wm.org/i3status/
COMMENT=	Small program for generating a status bar
LICENSE=	modified-bsd

USE_TOOLS+=	gmake

CONF_FILES=	${PREFIX}/share/examples/${PKGBASE}/i3status.conf ${PKG_SYSCONFDIR}/i3status.conf

MAKE_ENV+=	MANDIR=${PKGMANDIR}
MAKE_ENV+=	SYSCONFDIR=${PKG_SYSCONFDIR}
MAKE_ENV+=	DEBUG=0

.include "../../devel/confuse/buildlink3.mk"
.include "../../devel/yajl/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
