# $NetBSD: Makefile,v 1.6 2004/10/03 00:13:06 tv Exp $
#

DISTNAME=	juke-0.7
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://johan.nocrew.org/nav10/unix/juke/archive/

MAINTAINER=	mob@bicekru.org
HOMEPAGE=	http://johan.nocrew.org/nav10/unix/juke/
COMMENT=	Simple ncurses based jukebox

USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES
GNU_CONFIGURE=	YES

# halfdelay()
INCOMPAT_CURSES=	NetBSD-1.[45]*-* NetBSD-1.6[-_.]* NetBSD-1.6[A-L]-*

EGDIR=		${PREFIX}/share/examples/juke

CONF_FILES=	${EGDIR}/juke.conf.default ${PKG_SYSCONFDIR}/juke.conf

post-configure:
	@cd ${WRKSRC} && \
	for f in MANUAL doc/juke.1 src/conf.c; do		\
		${MV} $$f $$f.orig;				\
		${SED} ${FILES_SUBST_SED} $$f.orig > $$f;	\
	done

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/juke
	${INSTALL_DATA} ${WRKSRC}/juke.conf ${EGDIR}/juke.conf.default
	${INSTALL_DATA} ${WRKSRC}/MANUAL ${PREFIX}/share/doc/juke/

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
