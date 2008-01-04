# $NetBSD: Makefile,v 1.4 2008/01/04 12:18:27 ghen Exp $

DISTNAME=		ez-ipupdate-3.0.11b7
CATEGORIES=		net
MASTER_SITES=		http://www.ez-ipupdate.com/dist/

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://www.ez-ipupdate.com/
COMMENT=		Client to update dynamic DNS entries

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

EGDIR=			${PREFIX}/share/examples/ez-ipupdate
RCD_SCRIPTS=		ez-ipupdate

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_MESSAGE.path=	Correcting paths in example scripts.
SUBST_FILES.path=	example-*.conf example.conf
SUBST_SED.path=		-e "s|/usr/local|${PREFIX}|g"
SUBST_SED.path+=	-e "s|cache-file=/etc/|cache-file=${PKG_SYSCONFDIR}/|g"

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/example.conf ${DESTDIR}${EGDIR}/ez-ipupdate.conf
	${INSTALL_DATA} ${WRKSRC}/example-*.conf ${DESTDIR}${EGDIR}/

.include "../../mk/bsd.pkg.mk"
