# $NetBSD: Makefile,v 1.24 2002/02/18 15:14:05 seb Exp $
# FreeBSD Id: Makefile,v 1.4 1997/01/28 08:11:23 asami Exp 
#

DISTNAME=	gdbm-1.8.0
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GNU:=gdbm/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/gdbm/gdbm.html
COMMENT=	The GNU database manager

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
INFO_FILES=		gdbm.info
TEXINFO_OVERRIDE=	YES

post-extract:
	${RM} -f ${WRKSRC}/gdbm.info

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
