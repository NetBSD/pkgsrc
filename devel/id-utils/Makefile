# $NetBSD: Makefile,v 1.4 1998/04/15 10:38:20 agc Exp $
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

.include "../../mk/bsd.pkg.mk"
