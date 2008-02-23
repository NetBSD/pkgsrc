# $NetBSD: Makefile,v 1.10 2008/02/23 18:04:57 heinz Exp $
#

DISTNAME=		synergy-1.3.1
PKGREVISION=		3
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=synergy2/}

MAINTAINER=		yui@yui.pe.kr
HOMEPAGE=		http://synergy2.sourceforge.net/
COMMENT=		Let a user share a mouse and keyboard among computers

PKG_DESTDIR_SUPPORT=	user-destdir

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
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}/images
	set -e; cd ${WRKSRC}/doc; \
	for f in ${DOCS}; do \
		${INSTALL_DATA} "$$f" "${DESTDIR}${DOCDIR}/$$f"; \
	done
	${INSTALL_DATA_DIR} ${DESTDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/synergy.conf ${DESTDIR}${EXAMPLESDIR}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
