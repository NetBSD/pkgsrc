# $NetBSD: Makefile,v 1.12 2004/04/25 09:00:33 snj Exp $
#

DISTNAME=	ifcico-3.0.cm.alpha-4.1
PKGNAME=	ifcico-cm-3.0a4.1
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://cmeerw.org/files/

MAINTAINER=	tv@pobox.com
HOMEPAGE=	http://cmeerw.org/ifcico/
COMMENT=	FidoNet transport program using FTS protocols via dial or TCP

USE_BUILDLINK3=	yes

PKG_SYSCONFSUBDIR=	ifcico-cm
MAKE_ENV+=		PKG_SYSCONFDIR="${PKG_SYSCONFDIR}"

post-build:
	${SED} -e 's,@PREFIX@,${PREFIX},g' ${WRKSRC}/misc/config \
		>${WRKDIR}/config
	${SED} -e 's,@PREFIX@,${PREFIX},g' ${WRKSRC}/misc/config-global \
		>${WRKDIR}/config-global

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ifcico-cm
	${INSTALL_DATA} ${WRKDIR}/config* ${PREFIX}/share/examples/ifcico-cm/
	cd ${WRKSRC}/ifcico && for f in *.8; do \
		tbl <$$f >$$f.t && ${INSTALL_DATA} $$f.t ${PREFIX}/man/man8/$$f; \
	done

.include "../../mk/bsd.pkg.mk"
