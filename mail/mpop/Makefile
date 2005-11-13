# $NetBSD: Makefile,v 1.1.1.1 2005/11/13 03:09:20 minskim Exp $
#

DISTNAME=	mpop-0.8.2
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mpop/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	lems@gmx.net
HOMEPAGE=	http://mpop.sourceforge.net/
COMMENT=	Small, fast and portable POP3 client

GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--enable-nls

PKG_SYSCONFSUBDIR=	mpop

EGDIR=		${PREFIX}/share/examples/mpop
CONF_FILES=	${EGDIR}/mpoprc.example ${PKG_SYSCONFDIR}/mpoprc

INFO_FILES=	mpop.info

.include "options.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/mpoprc.example ${EGDIR}

.include "../../mk/bsd.pkg.mk"
