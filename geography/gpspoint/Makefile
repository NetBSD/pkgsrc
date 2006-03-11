# $NetBSD: Makefile,v 1.7 2006/03/11 10:07:50 ghen Exp $

DISTNAME=		gpspoint-2.030521
PKGREVISION=		1
CATEGORIES=		geography
MASTER_SITES=		http://gpspoint.dnsalias.net/gpspoint2/download/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://gpspoint.dnsalias.net/gpspoint2/
COMMENT=		Program to download and upload waypoints to and from your GPS device

DEPENDS+=		dialog>=0.6:../../misc/dialog

USE_PKGLOCALEDIR=       yes
USE_LIBTOOL=            yes
GNU_CONFIGURE=          yes

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/bin/bash
REPLACE.bash.new=	${SH}
REPLACE_FILES.bash=	src/mgpspoint

.include "../../mk/bsd.pkg.mk"
