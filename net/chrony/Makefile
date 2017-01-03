# $NetBSD: Makefile,v 1.34 2017/01/03 18:00:19 roy Exp $

DISTNAME=	chrony-1.31.1
PKGREVISION=	4
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
AUTO_MKDIRS=		yes

OWN_DIRS=		${VARBASE}/lib/chrony

EGDIR=			${PREFIX}/share/examples/chrony
EGFILES=		chrony.conf.example chrony.keys.example
RCD_SCRIPTS=		chronyd

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${EGFILES:S/^/examples\//} conf.c
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,@VARBASE@,${VARBASE},g'
SUBST_STAGE.paths=	post-patch

post-install:
	set -e; for file in ${EGFILES}; do			\
		${INSTALL_DATA} "${WRKSRC}/examples/$${file}"	\
			"${DESTDIR}${EGDIR}/$${file}";		\
	done

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
