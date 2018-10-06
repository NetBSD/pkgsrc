# $NetBSD: Makefile,v 1.35.2.1 2018/10/06 12:08:32 spz Exp $

DISTNAME=	chrony-3.4
CATEGORIES=	net
MASTER_SITES=	http://download.tuxfamily.org/chrony/

MAINTAINER=	hannken@NetBSD.org
HOMEPAGE=	http://chrony.tuxfamily.org/
COMMENT=	Daemon for maintaining the accuracy of computer clocks
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake
HAS_CONFIGURE=		YES
BUILD_DEFS+=		VARBASE
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--with-pidfile=${VARBASE}/run/chronyd.pid
AUTO_MKDIRS=		yes

OWN_DIRS=		${VARBASE}/lib/chrony

EGDIR=			${PREFIX}/share/examples/chrony
EGFILES=		chrony.conf.example3 chrony.keys.example
RCD_SCRIPTS=		chronyd

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${EGFILES:S/^/examples\//} conf.c
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,@VARBASE@,${VARBASE},g'
SUBST_STAGE.paths=	pre-configure

post-install:
	${INSTALL_DATA} "${WRKSRC}/examples/chrony.conf.example3" \
	    "${DESTDIR}${EGDIR}/chrony.conf.example";
	${INSTALL_DATA} "${WRKSRC}/examples/chrony.keys.example" \
	    "${DESTDIR}${EGDIR}/chrony.keys.example";

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
