# $NetBSD: Makefile,v 1.33 2003/09/28 09:13:58 jlam Exp $
#

DISTNAME=	vfu-3.04
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_BACKUP}
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.biscom.net/~cade/away/vfu/
COMMENT=	Small, handy, easy-to-use file manager

USE_BUILDLINK2=	# defined
USE_PKGINSTALL=	YES
USE_NCURSES=	# qiflush()

DOCDIR=		${PREFIX}/share/doc/vfu
EGDIR=		${PREFIX}/share/examples/vfu

CONF_FILES=	${EGDIR}/vfu.conf ${PKG_SYSCONFDIR}/vfu.conf

MAKE_ENV+=	PKG_SYSCONFDIR="${PKG_SYSCONFDIR}"

do-build:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${SH} build.netbsd

do-install:
	cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${SH} install

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR} ${EGDIR}
	cd ${WRKSRC};							\
	${INSTALL_DATA} COPYING INSTALL CONFIG FAQ HISTORY NOTES README \
		README.DOS THANKS.TO TODO XWINDOW.NOTES ${DOCDIR}
	cd ${WRKSRC};							\
	${INSTALL_DATA} ${WRKSRC}/vfu.conf ${EGDIR}/vfu.conf

.include "../../devel/ncurses/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
