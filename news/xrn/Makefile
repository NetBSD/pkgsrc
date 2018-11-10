# $NetBSD: Makefile,v 1.20 2018/11/10 20:03:40 wiz Exp $

DISTNAME=	xrn-10.11
CATEGORIES=	news
MASTER_SITES=	ftp://rtfm.mit.edu/pub/xrn/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://stuff.mit.edu/~jik/software/xrn.html
COMMENT=	USENET Newsreader for the X window system
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
# Note for gmake: Recent NetBSD make should work too, bmake-20150505 fails
USE_TOOLS+=	gmake lex pkg-config yacc

DOCDIR=		share/doc/xrn
INSTALLATION_DIRS+=	${DOCDIR}
INSTALLATION_DIRS+=	lib/X11/app-defaults

.include "../../mk/bsd.prefs.mk"

# Standard Xaw is the only variant supported by upstream
XAW_TYPE=	standard

# Experimental Xaw3d support for NetBSD
#.if ${OPSYS} == "NetBSD" && ${XAW_TYPE} == "3d"
#BUILDLINK_TRANSFORM+=	l:Xaw7:Xaw3d
#.PHONY: buildlink-Xaw3d-inc-hack
#post-wrapper: buildlink-Xaw3d-inc-hack
#
#buildlink-Xaw3d-inc-hack: buildlink-directories
#	cd ${BUILDLINK_DIR}/include/X11 && mv Xaw Xaw.standard && ln -s Xaw3d Xaw
#.endif

pre-install:
	for f in COMMON-PROBLMS COPYRIGHT CREDITS; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${DESTDIR}${PREFIX}/share/doc/xrn; \
	done

post-install:
	mv ${DESTDIR}${PREFIX}/etc/X11/app-defaults/XRn ${DESTDIR}${PREFIX}/lib/X11/app-defaults/XRn

.include "../../mk/xaw.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
