# New ports collection makefile for:	id-utils
# Version required:	3.2
# Date created:		22 Aug 1996
# Whom:			pst@freebsd.org
#
# $NetBSD: Makefile,v 1.3 1998/01/24 04:15:27 hubertf Exp $
# FreeBSD Id: Makefile,v 1.4 1996/11/18 10:22:47 asami Exp
#

DISTNAME=	id-utils-3.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	pst@FreeBSD.ORG

OPSYS!=		uname -s
.if (${OPSYS} == "FreeBSD")
# agc - don't do this if we're on NetBSD
# FreeBSD use emacs to byte-compile a .el file
BUILD_DEPENDS=	emacs:${PORTSDIR}/editors/emacs
.endif

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
