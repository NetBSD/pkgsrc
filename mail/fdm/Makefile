# $NetBSD: Makefile,v 1.6 2014/02/12 23:18:07 tron Exp $

DISTNAME=		fdm-1.7
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fdm/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://fdm.sourceforge.net/
COMMENT=		Fetch or receive mail and deliver it in various ways
LICENSE=		modified-bsd

HAS_CONFIGURE=		yes

INSTALLATION_DIRS+=	${EGDIR} ${DOCDIR}
EGDIR=			${PREFIX}/share/examples/fdm
DOCDIR=			${PREFIX}/share/doc/fdm

USE_TOOLS+=		yacc pax

.include "options.mk"

post-build:
	${RUN}cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		-f tools/dist.mk manual

post-install:
	cd ${WRKSRC}/examples && pax -rwpam . ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/MANUAL ${DESTDIR}${DOCDIR}

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../databases/tdb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
