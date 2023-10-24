# $NetBSD: Makefile,v 1.20 2023/10/24 22:09:43 wiz Exp $

DISTNAME=	fdm-2.2
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=nicm/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/nicm/fdm/
COMMENT=	Fetch or receive mail and deliver it in various ways
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	aclocal autoconf automake yacc pax

INSTALLATION_DIRS+=	${EGDIR} ${DOCDIR}
EGDIR=			${PREFIX}/share/examples/fdm
DOCDIR=			${PREFIX}/share/doc/fdm

CFLAGS.NetBSD+=		-D_OPENBSD_SOURCE	# needed for strtonum(3)

.include "options.mk"

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

post-install:
	cd ${WRKSRC}/examples && pax -rwpam . ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/MANUAL ${DESTDIR}${DOCDIR}

.include "../../databases/tdb/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
