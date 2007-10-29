# $NetBSD: Makefile,v 1.1.1.1 2007/10/29 09:48:31 seb Exp $
#

DISTNAME=		gsnmp-0.2.0
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.ibr.cs.tu-bs.de/local/gsnmp/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://trac.eecs.iu-bremen.de/projects/gsnmp/
COMMENT=		SNMP library

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/gnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
