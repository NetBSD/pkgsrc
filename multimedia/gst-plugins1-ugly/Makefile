# $NetBSD: Makefile,v 1.12 2023/11/16 09:22:51 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/}
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - ugly plugins

GST_PLUGINS+=	asfdemux
GST_PLUGINS+=	dvdlpcmdec
GST_PLUGINS+=	dvdsub
GST_PLUGINS+=	realmedia

GST_PLUGINS+=	nls

# generated with:
# find work/gst-*/ -name *.so | sed -e "s,/[^/]*$,:," -e 's,work/[^/]*/,${WRKSRC}/,' | tr -d \\n
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/gst/asfdemux:${WRKSRC}/output/gst/dvdlpcmdec:${WRKSRC}/output/gst/dvdsub:${WRKSRC}/output/gst/realmedia:${WRKSRC}/output/ext/x264

.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
