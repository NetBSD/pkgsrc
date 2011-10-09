# $NetBSD: Makefile,v 1.6 2011/10/09 10:02:45 cheusov Exp $
#

.include "../../pkgtools/pkg_online-server/Makefile.common"

PKGNAME=	${DISTNAME:C/online/online-server/}
CATEGORIES=	pkgtools
MAINTAINER=	cheusov@NetBSD.org
COMMENT+=	(server tools)

DEPENDS+=	dict-server>=1.10.10nb2:../../textproc/dict-server
DEPENDS+=	pkg_summary-utils>=0.18.1:../../pkgtools/pkg_summary-utils
DEPENDS+=	pipestatus-[0-9]*:../../devel/pipestatus

BUILD_DEPENDS+=	mk-configure>=0.20.0:../../devel/mk-configure

INSTALL_TARGET=	install-server install-doc

DOCDIR=		${PREFIX}/share/doc/pkg_online-server
EGDIR=		${PREFIX}/share/examples/pkg_online-server

MAKE_ENV+=	DOCDIR=${DOCDIR} EGDIR=${EGDIR}

CONF_FILES=	${EGDIR}/pkg_online_server.conf \
		${PKG_SYSCONFDIR}/pkg_online_server.conf

MAKE_PROGRAM=	mkcmake

.include "../../devel/mk-configure/configure.mk"
.include "../../mk/bsd.pkg.mk"
