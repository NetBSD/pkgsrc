# $NetBSD: Makefile,v 1.2 2018/11/20 23:42:59 leot Exp $

DISTNAME=	torsocks-2.3.0
CATEGORIES=	net
MASTER_SITES=	https://people.torproject.org/~dgoulet/torsocks/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitweb.torproject.org/torsocks.git
COMMENT=	Library to torify applications
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-conf=${PKG_SYSCONFDIR}/torsocks.conf

EGDIR=		${PREFIX}/share/examples/torsocks
CONF_FILES=	${EGDIR}/torsocks.conf \
		${PKG_SYSCONFDIR}/torsocks.conf

SUBST_CLASSES+=			configure
SUBST_STAGE.configure=		pre-configure
SUBST_MESSAGE.configure=	Fixing non-standard test(1) == operator
SUBST_FILES.configure=		configure
SUBST_SED.configure=		-e '/test/ s/ == / = /g'

SUBST_CLASSES+=			confdir
SUBST_STAGE.confdir=		pre-configure
SUBST_MESSAGE.confdir=		Adjusting confdir
SUBST_FILES.confdir=		doc/Makefile.in
SUBST_SED.confdir=		-e '/^confdir/ s;/tor;;'

SUBST_CLASSES+=			conffile
SUBST_STAGE.conffile=		pre-configure
SUBST_MESSAGE.conffile=		Adjusting DEFAULT_CONF_FILE
SUBST_FILES.conffile=		src/common/defaults.h
SUBST_SED.conffile=		-e '/DEFAULT_CONF_FILE/ s;"/tor/";"/";'

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fix hardcoded paths in man pages
SUBST_FILES.man=	doc/torsocks.1 doc/torsocks.8 doc/torsocks.conf.5
SUBST_SED.man=		-e 's;/etc/tor;${PKG_SYSCONFDIR};g'

TEST_TARGET=	check

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	cd ${DESTDIR}${PREFIX} && ${RM} -fr share/doc
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/torsocks.conf \
	    ${DESTDIR}${EGDIR}/torsocks.conf

.include "../../mk/bsd.pkg.mk"
