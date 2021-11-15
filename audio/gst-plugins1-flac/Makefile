# $NetBSD: Makefile,v 1.4 2021/11/15 22:01:16 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-flac/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - FLAC plugin

GST_PLUGINS+=	flac

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../audio/flac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
