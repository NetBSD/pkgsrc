# $NetBSD: Makefile,v 1.9 2023/06/06 12:42:10 riastradh Exp $
#

.include "../../pkgtools/pkg_online-server/Makefile.common"

PKGNAME=	${DISTNAME:C/online/online-server/}
CATEGORIES=	pkgtools
MAINTAINER=	cheusov@NetBSD.org
COMMENT+=	(server tools)

DEPENDS+=	dict-server>=1.10.10nb2:../../textproc/dict-server
DEPENDS+=	pkg_summary-utils>=0.60.0:../../pkgtools/pkg_summary-utils
DEPENDS+=	pipestatus-[0-9]*:../../devel/pipestatus

TOOL_DEPENDS+=	mk-configure>=0.20.0:../../devel/mk-configure

INSTALL_TARGET=	install-server install-doc

DOCDIR=		${PREFIX}/share/doc/pkg_online-server
EGDIR=		${PREFIX}/share/examples/pkg_online-server

MAKE_ENV+=	DOCDIR=${DOCDIR} EGDIR=${EGDIR}

CONF_FILES=	${EGDIR}/pkg_online_server.conf \
		${PKG_SYSCONFDIR}/pkg_online_server.conf

.include "../../devel/mk-configure/mk-c.mk"
.include "../../mk/bsd.pkg.mk"
