# $NetBSD: Makefile,v 1.3 2004/04/11 08:40:15 snj Exp $

DISTNAME=		gpspoint-2.030521
CATEGORIES=		geography
MASTER_SITES=		http://gpspoint.dnsalias.net/gpspoint2/download/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://gpspoint.dnsalias.net/gpspoint2/
COMMENT=		Program to download and upload waypoints to and from your GPS device

DEPENDS+=		dialog>=0.6:../../misc/dialog

USE_BUILDLINK3=         yes
USE_PKGLOCALEDIR=       yes
USE_LIBTOOL=            yes
GNU_CONFIGURE=          yes

.include "../../mk/bsd.pkg.mk"
