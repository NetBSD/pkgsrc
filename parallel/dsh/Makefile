# $NetBSD: Makefile,v 1.1 2014/01/10 22:43:33 cheusov Exp $
#

DISTNAME=	dsh-0.25.10
CATEGORIES=	parallel
MASTER_SITES=	http://www.netfort.gr.jp/~dancer/software/downloads/

MAINTAINER=	morr@NetBSD.org
HOMEPAGE=	http://www.netfort.gr.jp/~dancer/software/downloads/
COMMENT=	Runs command through rsh or ssh on a cluster of machines
LICENSE=	gnu-gpl-v2

EGDIR=			${PREFIX}/share/examples/dsh
GNU_CONFIGURE=		yes
USE_TOOLS+=		msgfmt
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
CONF_FILES=		${EGDIR}/dsh.conf ${PKG_SYSCONFDIR}/dsh.conf

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libdshconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
