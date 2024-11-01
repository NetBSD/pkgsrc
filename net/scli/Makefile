# $NetBSD: Makefile,v 1.48 2024/11/01 12:54:02 wiz Exp $

DISTNAME=		scli-0.3.1
PKGREVISION=		20
CATEGORIES=		net
#MASTER_SITES=		ftp://ftp.ibr.cs.tu-bs.de/local/scli/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://www.ibr.cs.tu-bs.de/projects/scli/
COMMENT=		SNMP command line interface

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config gmake

BUILDLINK_API_DEPENDS.readline+=	readline>=4.0

INFO_FILES=		yes

.include "../../devel/glib2/buildlink3.mk"
# history_list
.include "../../devel/readline/buildlink3.mk"
.include "../../net/gnet/buildlink3.mk"
.include "../../net/gsnmp/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
