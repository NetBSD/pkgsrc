# New ports collection makefile for:    linux_lib
# Version required:	2.1
# Date created:         
# Whom:                 erich@FreeBSD.org
#
# $NetBSD: Makefile,v 1.2 1997/12/29 19:08:52 hubertf Exp $
# FreeBSD Id: Makefile,v 1.19 1997/12/04 17:34:28 asami Exp
#

ONLY_FOR_ARCHS=	i386
DISTNAME=	linux_lib-2.4
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	erich@FreeBSD.org

PREFIX=		/emul/linux
NO_MTREE=	yes
NO_BUILD=	yes
EXTRACT_ONLY=	# empty
NO_WRKSUBDIR=	yes

pre-install:
	@[ -d ${PREFIX} ] || ${MKDIR} ${PREFIX}

do-install:
	@zcat ${DISTDIR}/${DISTNAME}.tar.gz |(cd ${PREFIX}; pax -r)

post-install:
	-${PREFIX}/sbin/ldconfig
	${MKDIR} ${PREFIX}/usr/lib/zoneinfo
	ln -sf /etc/localtime /${PREFIX}/usr/lib/zoneinfo/localtime

.include <bsd.port.mk>
