# $NetBSD: Makefile,v 1.9 2022/04/18 12:36:09 nia Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/}
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - ugly plugins

GST_PLUGINS+=	asfdemux
GST_PLUGINS+=	dvdlpcmdec
GST_PLUGINS+=	dvdsub
GST_PLUGINS+=	realmedia
GST_PLUGINS+=	xingmux

GST_PLUGINS+=	nls

# generated with:
# find work/gst-*/ -name *.so | sed -e "s,/[^/]*$,:," -e 's,work/[^/]*/,${WRKSRC}/,' | tr -d \\n
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/gst/asfdemux:${WRKSRC}/output/gst/dvdlpcmdec:${WRKSRC}/output/gst/dvdsub:${WRKSRC}/output/gst/realmedia:${WRKSRC}/output/gst/xingmux:${WRKSRC}/output/ext/x264

.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
