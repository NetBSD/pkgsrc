# New ports collection makefile for:    linux_lib
# Version required:	2.1
# Date created:         1997/12/04
# Whom:                 erich@FreeBSD.org
#
# $NetBSD: Makefile,v 1.5 1998/02/02 08:10:49 hubertf Exp $
# FreeBSD Id: Makefile,v 1.19 1997/12/04 17:34:28 asami Exp
#

DISTNAME=	linux_lib-2.4
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_LOCAL}
ONLY_FOR_ARCHS=	i386

MAINTAINER=	erich@FreeBSD.org

PREFIX=		/emul/linux

# The distfile is distributed under the GPL, so no re-distribution of
# binaries without source.
MIRROR_DISTFILE=	no

NO_MTREE=	yes
NO_BUILD=	yes
EXTRACT_ONLY=	# empty
NO_WRKSUBDIR=	yes

pre-install:
	@[ -d ${PREFIX} ] || ${MKDIR} ${PREFIX}

do-install:
	@zcat ${DISTDIR}/${DISTNAME}.tar.gz |(cd ${PREFIX}; pax -r)

post-install:
	-${LDCONFIG} || ${TRUE}
	${MKDIR} ${PREFIX}/usr/lib/zoneinfo
	ln -sf /etc/localtime ${PREFIX}/usr/lib/zoneinfo/localtime

.include <bsd.port.mk>
