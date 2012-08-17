# $NetBSD: Makefile,v 1.1.1.1 2012/08/17 17:45:40 seb Exp $

DISTNAME=		fdm-1.6
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fdm/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://fdm.sourceforge.net/
COMMENT=		Fetch or receive mail and deliver it in various ways
LICENSE=		modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+=	${EGDIR} ${DOCDIR}
EGDIR=			${PREFIX}/share/examples/fdm
DOCDIR=			${PREFIX}/share/doc/fdm

USE_TOOLS+=		pax
MAKE_ENV+=		PCRE=1

post-install:
	cd ${WRKSRC}/examples && pax -rwpam . ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/MANUAL ${DESTDIR}${DOCDIR}

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../databases/tdb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
