# $NetBSD: Makefile,v 1.5 2020/01/26 17:31:59 rillig Exp $
#

DISTNAME=	dsh-0.25.10
PKGREVISION=	1
CATEGORIES=	parallel
MASTER_SITES=	http://www.netfort.gr.jp/~dancer/software/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.netfort.gr.jp/~dancer/software/downloads/
COMMENT=	Runs command through rsh or ssh on a cluster of machines
LICENSE=	gnu-gpl-v2

EGDIR=			${PREFIX}/share/examples/dsh
GNU_CONFIGURE=		yes
USE_TOOLS+=		msgfmt
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
CONF_FILES=		${EGDIR}/dsh.conf ${PKG_SYSCONFDIR}/dsh.conf

INSTALL_MAKE_FLAGS=	sysconfdir=${EGDIR}

LIBS=			-liconv -lintl

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libdshconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
