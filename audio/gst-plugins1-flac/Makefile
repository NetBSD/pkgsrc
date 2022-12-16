# $NetBSD: Makefile,v 1.6 2022/12/16 21:08:10 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-flac/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - FLAC plugin

GST_PLUGINS+=	flac

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../audio/flac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
