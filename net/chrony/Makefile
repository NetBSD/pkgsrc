# $NetBSD: Makefile,v 1.11 2004/04/25 08:14:54 snj Exp $

DISTNAME=	chrony-1.17
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://chrony.sunsite.dk/projects/chrony/

MAINTAINER=	hannken@NetBSD.org
HOMEPAGE=	http://chrony.sunsite.dk/index.php
COMMENT=	Daemon for maintaining the accuracy of computer clocks

USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--prefix=${PREFIX}

EGDIR=			${LOCALBASE}/share/examples/chrony
EGFILES=		chrony.conf.example chrony.keys.example
RCD_SCRIPTS=		chronyd

pre-install:
	for file in ${EGFILES}; do				\
		${SED} ${FILES_SUBST_SED}			\
			${WRKSRC}/examples/$${file} >		\
			${WRKDIR}/$${file};			\
	done

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	for file in ${EGFILES}; do				\
		${INSTALL_DATA} ${WRKDIR}/$${file}		\
			${EGDIR}/$${file};			\
	done

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
