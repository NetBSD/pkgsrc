# $NetBSD: Makefile,v 1.2 2002/09/19 08:41:50 jlam Exp $

DISTNAME=	chrony-1.17
CATEGORIES=	net
MASTER_SITES=	ftp://chrony.sunsite.dk/projects/chrony/

MAINTAINER=	hannken@netbsd.org
HOMEPAGE=	http://go.to/chrony
COMMENT=	Daemon for maintaining the accuracy of computer clocks

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--prefix=${LOCALBASE}

EGDIR=			${LOCALBASE}/share/examples/chrony
EGFILES=		chrony.conf.example chrony.keys.example
RCD_SCRIPTS=		chronyd

pre-install:
	${SED} ${FILES_SUBST_SED} \
		${FILESDIR}/chronyd.sh > ${WRKDIR}/chronyd
	for file in ${EGFILES}; do				\
		${SED} ${FILES_SUBST_SED}			\
			${WRKSRC}/examples/$${file} >		\
			${WRKDIR}/$${file};			\
	done

post-install:
	for script in ${RCD_SCRIPTS}; do			\
		${INSTALL_SCRIPT} ${WRKDIR}/$${script}		\
		${LOCALBASE}/etc/rc.d/$${script};		\
	done
	${INSTALL_DATA_DIR} ${EGDIR}
	for file in ${EGFILES}; do				\
		${INSTALL_DATA} ${WRKDIR}/$${file}		\
			${EGDIR}/$${file};			\
	done

.include "../../devel/readline/buildlink.mk"
.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
