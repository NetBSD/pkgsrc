# $NetBSD: Makefile,v 1.10 2020/03/08 16:50:52 wiz Exp $
#

DISTNAME=		gsnmp-0.2.0
PKGREVISION=		5
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.ibr.cs.tu-bs.de/local/gsnmp/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		https://trac.eecs.iu-bremen.de/projects/gsnmp/
COMMENT=		SNMP library

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/gnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
