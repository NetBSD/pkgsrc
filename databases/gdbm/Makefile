# $NetBSD: Makefile,v 1.28 2003/06/02 01:21:09 jschauma Exp $
#

DISTNAME=	gdbm-1.8.3
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GNU:=gdbm/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/gdbm/gdbm.html
COMMENT=	The GNU database manager

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
INFO_FILES=		gdbm.info
TEXINFO_OVERRIDE=	YES
CONFIG_GUESS_OVERRIDE=	${WRKSRC}/config.guess
CONFIG_SUB_OVERRIDE=	${WRKSRC}/config.sub

post-extract:
	${RM} -f ${WRKSRC}/gdbm.info

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
