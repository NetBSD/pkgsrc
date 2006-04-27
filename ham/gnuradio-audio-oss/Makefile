# $NetBSD: Makefile,v 1.6 2006/04/27 03:04:26 wulf Exp $

VERSION=	0.9
DISTNAME=	gr-audio-oss-${VERSION}
PKGNAME=	gnuradio-audio-oss-${VERSION}
WRKSRC=		${WRKDIR}/${DISTNAME}
COMMENT=	Open Sound System support for GNU Radio

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONF_FILES+=	${EGDIR}/gr-audio-oss.conf ${PKG_SYSCONFDIR}/gr-audio-oss.conf
CONFIGURE_ARGS+=--sysconfdir=${PREFIX}/share/examples

.include "../../mk/oss.buildlink3.mk"
.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
