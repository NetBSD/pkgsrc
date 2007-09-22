# $NetBSD: Makefile,v 1.9 2007/09/22 18:22:18 minskim Exp $
#

DISTNAME=		synergy-1.3.1
PKGREVISION=		3
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=synergy2/}

MAINTAINER=		yui@yui.pe.kr
HOMEPAGE=		http://synergy2.sourceforge.net/
COMMENT=		Let an user share a mouse and keyboard among computers

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
EXAMPLESDIR=		${PREFIX}/share/examples/${PKGBASE}
DOCS=			*.html *.css images/*.gif

.if !exists(/System/Library/Frameworks/Carbon.framework)
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.endif

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}/images
	cd ${WRKSRC}/doc; \
	for f in ${DOCS}; do \
		${INSTALL_DATA} $$f ${DOCDIR}/$$f; \
	done
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/synergy.conf ${EXAMPLESDIR}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
