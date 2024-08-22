# $NetBSD: Makefile,v 1.15 2024/08/22 17:05:58 gdt Exp $

DISTNAME=		gpspoint-2.030521
PKGREVISION=		1
CATEGORIES=		geography
MASTER_SITES=		#http://gpspoint.dnsalias.net/gpspoint2/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://gpspoint.dnsalias.net/gpspoint2/
COMMENT=		Program to download and upload waypoints to and from your GPS device
LICENSE=		gnu-gpl-v2

DEPENDS+=		dialog>=0.6:../../misc/dialog

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/bin/bash
REPLACE.bash.new=	${SH}
REPLACE_FILES.bash=	src/mgpspoint

.include "../../mk/bsd.pkg.mk"
