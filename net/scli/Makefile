# $NetBSD: Makefile,v 1.19 2006/04/06 03:12:46 jlam Exp $
#

DISTNAME=		scli-0.2.12
PKGREVISION=		6
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.ibr.cs.tu-bs.de/pub/local/scli/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ibr.cs.tu-bs.de/projects/scli/
COMMENT=		SNMP command line interface

GNU_CONFIGURE=		yes

USE_GNU_READLINE=	# history_list
BUILDLINK_DEPENDS.readline+=    readline>=4.0

INFO_FILES=		scli.info

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
