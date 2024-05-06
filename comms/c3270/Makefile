# $NetBSD: Makefile,v 1.3 2024/05/06 08:40:22 jperkin Exp $

DISTNAME=	suite3270-4.1ga11-src
PKGNAME=	c3270-4.1ga11
PKGREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	http://x3270.bgp.nu/download/04.01/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://x3270.bgp.nu/
COMMENT=	3270 Terminal emulator for ncurses
LICENSE=	modified-bsd

WRKSRC=			${WRKDIR}/suite3270-4.1
CONFLICTS=		x3270-[0-9]*
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-c3270
USE_TOOLS+=		gmake pkg-config

PKG_SYSCONFSUBDIR=	x3270
EGDIR=			share/examples/c3270
INSTALLATION_DIRS+=	${EGDIR}
CONF_FILES+=		${EGDIR}/ibm_hosts ${PKG_SYSCONFDIR}/ibm_hosts

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/ibm_hosts ${DESTDIR}${PREFIX}/${EGDIR}


.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
