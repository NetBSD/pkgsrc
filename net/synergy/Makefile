# $NetBSD: Makefile,v 1.6 2006/08/17 14:02:23 taca Exp $
#

DISTNAME=		synergy-1.3.1
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=synergy2/}

MAINTAINER=		yui@yui.pe.kr
HOMEPAGE=		http://synergy2.sourceforge.net/
COMMENT=		Let an user share a mouse and keyboard among computers

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

DOCDIR=			${PREFIX}/share/doc/html/${PKGBASE}
EXAMPLSEDIR=		${PREFIX}/share/examples/${PKGBASE}
DOCS=			*.html *.css images/*.gif

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}/images
	cd ${WRKSRC}/doc; \
	for f in ${DOCS}; do \
		${INSTALL_DATA} $$f ${DOCDIR}/$$f; \
	done
	${INSTALL_DATA_DIR} ${EXAMPLSEDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/synergy.conf ${EXAMPLSEDIR}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
