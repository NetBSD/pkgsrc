# $NetBSD: Makefile,v 1.9 2016/03/05 11:28:48 jperkin Exp $

DISTNAME=	fdm-1.9
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=nicm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nicm/fdm/
COMMENT=	Fetch or receive mail and deliver it in various ways
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	aclocal autoconf automake yacc pax

INSTALLATION_DIRS+=	${EGDIR} ${DOCDIR}
EGDIR=			${PREFIX}/share/examples/fdm
DOCDIR=			${PREFIX}/share/doc/fdm

CONFIGURE_ENV+=	ac_cv_func_mremap=no	# avoid mremap(2)

CFLAGS.NetBSD+=	-D_OPENBSD_SOURCE	# needed for strtonum(3)

.include "options.mk"

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

post-install:
	cd ${WRKSRC}/examples && pax -rwpam . ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/MANUAL ${DESTDIR}${DOCDIR}

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../databases/tdb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
