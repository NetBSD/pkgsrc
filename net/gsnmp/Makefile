# $NetBSD: Makefile,v 1.11 2021/04/24 11:40:49 wiz Exp $

DISTNAME=		gsnmp-0.2.0
PKGREVISION=		5
CATEGORIES=		net
#MASTER_SITES=		ftp://ftp.ibr.cs.tu-bs.de/local/gsnmp/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		https://trac.eecs.iu-bremen.de/projects/gsnmp/
COMMENT=		SNMP library

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/gnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
