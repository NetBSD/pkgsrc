# $NetBSD: Makefile,v 1.8 1998/10/01 21:03:33 garbled Exp $
# FreeBSD Id: Makefile,v 1.4 1996/11/18 10:22:47 asami Exp
#

DISTNAME=	id-utils-3.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/idutils/idutils.html

OPSYS!=		uname -s
.if (${OPSYS} == "FreeBSD")
# agc - don't do this if we're on NetBSD
# FreeBSD use emacs to byte-compile a .el file
BUILD_DEPENDS=	emacs:../../editors/emacs
.endif

INFO_FILES=	id-utils.info
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include "../../mk/bsd.pkg.mk"
