# New ports collection makefile for:	tkinfo
# Version required:     1.5
# Date created:         16 Jan 1995
# Whom:                 thomas@ghpc8.ihf.rwth-aachen.de
#
# $Id: Makefile,v 1.2 1997/10/27 01:30:27 hubertf Exp $
#

DISTNAME=	tkinfo-1.5
CATEGORIES=	misc tk80
MASTER_SITES=	http://www.math.ucsb.edu/~boldt/tkinfo/ \
		http://math-www.uni-paderborn.de/~axel/tkinfo/

MAINTAINER=	tg@freebsd.org

RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11/tk80
NO_BUILD=	yes

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/tkinfo ${PREFIX}/bin

post-patch:
	( cd ${WRKSRC} ; ${SED} 's|@PREFIX@|'${PREFIX}'|g' \
		<tkinfo >tkinfo.BAK ; mv tkinfo.BAK tkinfo )

.include <bsd.port.mk>
