# $NetBSD: Makefile,v 1.2 2014/01/12 15:30:12 cheusov Exp $
#

DISTNAME=	dsh-0.25.10
CATEGORIES=	parallel
MASTER_SITES=	http://www.netfort.gr.jp/~dancer/software/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
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
