# $NetBSD: Makefile,v 1.6 1998/04/24 09:20:34 agc Exp $
# FreeBSD Id: Makefile,v 1.4 1996/11/18 10:22:47 asami Exp
#

DISTNAME=	id-utils-3.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	packages@netbsd.org

OPSYS!=		uname -s
.if (${OPSYS} == "FreeBSD")
# agc - don't do this if we're on NetBSD
# FreeBSD use emacs to byte-compile a .el file
BUILD_DEPENDS=	emacs:../../editors/emacs
.endif

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include "../../mk/bsd.pkg.mk"
