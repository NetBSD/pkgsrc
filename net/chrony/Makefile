# $NetBSD: Makefile,v 1.3 2002/09/19 09:04:14 jlam Exp $

DISTNAME=	chrony-1.17
CATEGORIES=	net
MASTER_SITES=	ftp://chrony.sunsite.dk/projects/chrony/

MAINTAINER=	hannken@netbsd.org
HOMEPAGE=	http://go.to/chrony
COMMENT=	Daemon for maintaining the accuracy of computer clocks

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

.include "../../devel/readline/buildlink.mk"
.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
